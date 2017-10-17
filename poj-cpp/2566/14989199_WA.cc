#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int arr[maxn], N, K, t, ra[maxn], bak[maxn];

int cmp(int a, int b)
{
	return arr[a] < arr[b];
}

int main()
{
	//freopen("in", "r", stdin);
	while(~scanf("%d%d", &N, &K)) {
		if(!N && !K) break;
		for(int i=1; i<=N; i++)
			scanf("%d", &arr[i]);
		for(int i=1; i<=N; i++)
			arr[i] += arr[i-1];
		for(int i=0; i<=N; i++)
			bak[i] = arr[i];
		for(int i=0; i<=N; i++)
			ra[i] = i;
		sort(ra, ra+N+1, cmp);
		sort(arr, arr+N+1);
		while(K--) {
			scanf("%d", &t);
			int ans = 0x3f3f3f3f;
			int l, r;
			for(int s=0; s<N; s++) {
				int t1 = lower_bound(arr+s, arr+N+1, arr[s]+t) - arr;
				if(t1<=N && abs(arr[t1]-arr[s] - t) < ans) {
					ans = abs(arr[t1]-arr[s] - t);
					l = ra[s]; r = ra[t1];
				}
				if(t1>0 && abs(arr[t1-1]-arr[s] - t) < ans) {
					ans = abs(arr[t1-1]-arr[s] - t);
					l = ra[s]; r = ra[t1-1];
				}
				int t2 = lower_bound(arr+s, arr+N+1, arr[s]-t) - arr;
				if(t2<=N && abs(arr[t2]-arr[s] + t) < ans) {
					ans = abs(arr[t2]-arr[s] + t);
					l = ra[s]; r = ra[t2];
				}
				if(t2>0 && abs(arr[t2-1]-arr[s] + t) < ans) {
					ans = abs(arr[t2-1]-arr[s] + t);
					l = ra[s]; r = ra[t2-1];
				}
			}
			if(l>r) swap(l, r);
			printf("%d %d %d\n", abs(bak[r]-bak[l]), l+1, r);
		}
	}

	return 0;
}

/**
0 -10 -15 0 -10 0
-15 -10 -10 0 0 0 
  2   1   4 0 3 5


*/





