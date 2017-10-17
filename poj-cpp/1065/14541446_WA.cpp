#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

P arr[5050];
int dp[5050], vst[5050], cnt;

int lis(int N)
{
	int ans = 0;
	for(int i=0; i<N; i++) dp[i] = 1;
	for(int i=0; i<N; i++) {
		if(vst[i]) continue;
		for(int j=0; j<i; j++) {
			if(vst[j]) continue;
			if(arr[j].second<=arr[i].second && dp[j]+1>dp[i]) {
				dp[i] = dp[j]+1;
			}
		}
	}
	for(int i=0; i<N; i++)
		if(dp[i]==1) ans++;

	return ans;
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
		printf("%d\n", lis(N));
	}

	return 0;
}











