
#include <stdio.h>
#include <string.h>

int arr[1024][128], ans;

int dfs(int n, int k);

int main()
{
	int N, K, i;

	memset(arr, 0, sizeof(arr));
	ans = 0;
	scanf("%d%d", &N, &K);
	dfs(N, K);
	printf("%d\n", ans);

	return 0;
}

int dfs(int n, int k)
{
	if(n==0) return ans += 1;
	else if(k==0) return 0;
	else if(arr[n][k]) return arr[n][k];
	else if(k>n) return arr[n][k] = dfs(n, n);
	else {
		for(int i=0; n-k*i>=0; i++) {
			///printf("%d ", n-k*i);
			arr[n][k] = dfs(n-k*i, k-1);
		}
	}
	return 0;
}
