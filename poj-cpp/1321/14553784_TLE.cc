#include <stdio.h>
#include <string.h>

char maps[15][15];
int N, K, ans, M;

void dfs(int r, int n, int sta)
{
	if(n==0) {
		ans++;
		return ;
	}
	if(r==M) return ;
	for(int j=0; j<N; j++) {
		if(maps[r][j]!='#')
			continue;
		if(sta & (1<<j)) continue;
		dfs(r+1, n-1, sta|(1<<j));
		dfs(r+1, n, sta);
	}
}

int is_used(char *str)
{
	for(int i=0; i<N; i++) {
		if(str[i]=='#') return 1;
	}
	return 0;
}


int main()
{
	while(scanf("%d%d", &N, &K)) {
		if(N==-1 && K==-1) break;
		memset(maps, 0, sizeof(maps));
		int j = 0;
		for(int i=0; i<N; i++) {
			scanf("%s", maps[j]);
			if(is_used(maps[j])) j++;
		}
		M = j;
		ans = 0;
		dfs(0, K, 0);
		printf("%d\n", ans);
	}

	return 0;
}










