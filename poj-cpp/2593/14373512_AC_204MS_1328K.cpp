#include <stdio.h>
#define INF 99999999

int lans[100005], rans[100005], arr[100005], N;

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int i, ans;

	while(scanf("%d", &N) && N) {
		for(i=1; i<=N; i++)
			scanf("%d", &arr[i]);
		lans[0] = rans[N+1] = 0;
		for(i=1; i<=N; i++) {
			lans[i] = max(0, lans[i-1]) + arr[i];
		}
		for(i=N; i>0; i--) {
			rans[i] = max(0, rans[i+1]) + arr[i];
		}
		for(i=2; i<=N; i++) lans[i] = max(lans[i], lans[i-1]);
		for(i=N-1; i>0; i--) rans[i] = max(rans[i], rans[i+1]);
		ans = -INF;
		for(i=1; i<N; i++) {
			ans = max(ans, lans[i]+rans[i+1]);
		}
		printf("%d\n", ans);
	}

	return 0;
}
