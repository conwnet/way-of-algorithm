#include <stdio.h>
#define INF 99999999

int lans[1000005], rans[1000005], arr[1000005], N;
int lst[2000010], rst[2000010];

int max(int a, int b)
{
	return a>b?a:b;
}

int build_l(int L, int R, int o)
{
	if(L==R) return lst[o] = lans[L];
	int M = (L+R)>>1;
	int a = build_l(L, M, o*2);
	int b = build_l(M+1, R, o*2+1);
	return lst[o] = max(a, b);
}

int build_r(int L, int R, int o)
{
	if(L==R) return rst[o] = rans[L];
	int M = (L+R)>>1;
	int a = build_r(L, M, o*2);
	int b = build_r(M+1, R, o*2+1);
	return rst[o] = max(a, b);
}

int query_l(int L, int R, int o, int l, int r)
{
	if(l<=L && r>=R) return lst[o];
	int M = (L+R)>>1;
	int a = -INF, b = -INF;
	if(l<=M) a = query_l(L, M, o*2, l, r);
	if(r>M) b = query_l(M+1, R, o*2+1, l, r);
	return max(a, b);
}

int query_r(int L, int R, int o, int l, int r)
{
	if(l<=L && r>=R) return rst[o];
	int M = (L+R)>>1;
	int a = -INF, b = -INF;
	if(l<=M) a = query_r(L, M, o*2, l, r);
	if(r>M) b = query_r(M+1, R, o*2+1, l, r);
	return max(a, b);
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
		build_l(1, N, 1);
		build_r(1, N, 1);
		ans = -INF;
		for(i=1; i<N; i++) {
			int a = query_l(1, N, 1, 1, i);
			int b = query_r(1, N, 1, i+1, N);
			ans = max(ans, a+b);
		}
		printf("%d\n", ans);
	}

	return 0;
}
