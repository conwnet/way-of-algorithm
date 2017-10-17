#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M, dp[110][100][100];
int hi[110];

int cnt, path[15] = {0}, per[10024];

void dfs(int s)
{
	if(s>M) {
		int tmp = 0;
		for(int i=1; i<=M; i++) {
			tmp = tmp*2 + path[i];
		}
		//for(int i=1; i<=M; i++) printf("%d ", path[i]); printf("\n");
		//printf("%d \n", cnt);
		per[cnt++] = tmp;
		return ;
	}
	for(int i=s; i<=M; i++) {
		path[i] = 1;
		dfs(i+3);
		path[i] = 0;
	}
}

int count(int n)
{
	int tmp = 0;
	for(int i=0; i<M; i++) {
		if(n & (1<<i)) tmp++;
	}
	return tmp;
}

int main()
{
	char str[15];
	cnt = 1;
	scanf("%d%d", &N, &M);
	dfs(1);
	for(int i=0; i<N; i++) {
		scanf("%s", str);
		int tmp = 0;
		for(int j=0; j<M; j++)
			tmp = tmp*2 + (str[j]=='H'?1:0);
		hi[i] = tmp;
		//printf("%d \n", i);
	}
	for(int i=0; i<cnt; i++) {
		if(hi[i] & per[i]) continue;
		dp[0][i][0] = count(per[i]);
	}
	for(int i=0; i<cnt; i++) {
		if(per[i] & hi[1]) continue;
		for(int j=0; j<cnt; j++) {
			if(per[i] & per[j]) continue;
			dp[1][i][j] = max(dp[i][i][j], dp[0][j][0] + count(per[j]));
		}
	}
	for(int i=2; i<N; i++) {
		for(int j=0; j<cnt; j++) {
			if(per[j] & hi[i]) continue;
			for(int k=0; k<cnt; k++) {
				for(int m=0; m<cnt; m++) {
					if(per[k] & per[m]) continue;
					if(per[j] & per[m]) continue;
					dp[i][j][k] = max(dp[i][j][k],
					dp[i-1][k][m] + count(per[j]));
				}
			}
		}
	}
	int ans = 0;
	for(int i=0; i<cnt; i++) {
		for(int j=0; j<cnt; j++) {
			ans = max(ans, dp[N-1][i][j]);
		}
	}
	printf("%d\n", ans-1);

	return 0;
}






