#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

P arr[5050];
int dp[5050], prev[5050], vst[5050], cnt;

int lis(int N)
{

	memset(dp, 0, sizeof(dp));
	memset(prev, -1, sizeof(prev));
	dp[0] = 1;
	for(int i=0; i<N; i++) {
		if(vst[i]) continue;
		for(int j=0; j<i; j++) {
			if(vst[j]) continue;
			if(arr[j].second<=arr[i].second && dp[j]+1>=dp[i]) {
				dp[i] = dp[j]+1;
				prev[i] = j;
			}
		}
	}
	//for(int i=0; i<N; i++) printf("   %d", dp[i]);
	int maxs = dp[0];
	int flag = 0;
	for(int i=1; i<N; i++) {
		if(dp[i]>=maxs) {
			maxs = dp[i];
			flag = i;
		}
	}
	for(int i=flag; i!=-1; i=prev[i]) {
		//printf("%d %d\n", arr[i].first, arr[i].second);
		vst[i] = 1;
		cnt++;
	}
	//printf("\n");

	return 1;
}

int main()
{
	int T, N;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d%d", &arr[i].first, &arr[i].second);;
		}
		sort(arr, arr+N);
		//for(int i=0; i<N; i++) printf("%d %d\n", arr[i].first, arr[i].second); printf("\n");
		cnt = 0;
		int ans = 0;
		memset(vst, 0, sizeof(vst));
		while(cnt<N) {
			ans += lis(N);
		}
		printf("%d\n", ans);
	}

	return 0;
}















