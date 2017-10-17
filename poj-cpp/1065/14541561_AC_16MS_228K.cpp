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
	memset(vst, 0, sizeof(vst));
	for(int i=0; i<N; i++) dp[i] = 1;
	for(int i=0; i<N; i++) {
		if(vst[i]) continue;
		ans ++;
		int prev = arr[i].second;
		for(int j=i+1; j<N; j++) {
			if(!vst[j] && arr[j].second >= prev) {
				vst[j] = 1;
				prev = arr[j].second;
			}
		}
	}

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
		printf("%d\n", lis(N));
	}

	return 0;
}







