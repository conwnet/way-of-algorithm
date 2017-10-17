#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int arr[maxn], N, K, t;

int main()
{
	//freopen("in", "r", stdin);
	while(~scanf("%d%d", &N, &K)) {
		if(!N && !K) break;
		for(int i=1; i<=N; i++) {
			scanf("%d", &arr[i]);
			if(arr[i] < 0) arr[i] = -arr[i];
		}
		for(int i=1; i<=N; i++)
			arr[i] += arr[i-1];
		while(K--) {
			scanf("%d", &t);
			int ans = 0x3f3f3f3f;
			int l, r;
			for(int s=1; s<=N; s++) {
				for(int i=s; i<=N; i++) {
					int tmp = abs(arr[i]-arr[s-1] - t);
					if(tmp < ans) {
						ans = tmp;
						l = s;
						r = i;
					}
					if(arr[i]-arr[s-1]-t > ans) break;
				}
			}
			printf("%d %d %d\n", arr[r]-arr[l-1], l, r);
		}
	}

	return 0;
}
