#include <stdio.h>
#include <string.h>

int sum[200000], lazy[200000], N, M;

int push_down(int L, int R, int o)
{
	if(L!=R) {
		lazy[o*2] = lazy[o];
		lazy[o*2+1] = lazy[o];
	}
	sum[o] = lazy[o]*(R-L+1);
	lazy[o] = -1;
	return sum[o];
}

int update(int L, int R, int o, int l, int r, int x)
{
	if(lazy[o]!=-1) push_down(L, R, o);
	if(l<=L && r>=R) {
		lazy[o] = x;
		return (R-L+1)*x;
	}
	if(l>R || r<L) return sum[o];
	int M = (L+R)>>1;
	int a = update(L, M, o*2, l, r, x);
	int b = update(M+1, R, o*2+1, l, r, x);
	return sum[o] = a+b;
}

int query(int L, int R, int o, int l, int r)
{
	if(lazy[o]!=-1) push_down(L, R, o);
	if(l<=L && r>=R) return sum[o];
	int a = 0; int b = 0;
	int M = (L+R)>>1;
	if(l<=M) a = query(L, M, o*2, l, r);
	if(r>M) b = query(M+1, R, o*2+1, l, r);
	return a+b;
}


int main()
{
	int op, a, b, l, r, m, cnt, to;

	memset(sum, 0, sizeof(sum));
	memset(lazy, -1, sizeof(lazy));
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &op, &a);
		if(op==1) {
			l = 1; r = N;
			while(l<r) {
				m = (l+r)>>1;
				cnt = query(1, N, 1, 1, m);
				if(m-cnt<a) l = m+1;
				else r = m;
			}
			if(l==N && N-query(1, N, 1, 1, N)<a) {
				printf("0\n");
				continue;
			} else to = l;
			l = 1; r = N;
			while(l<r) {
				m = (l+r)>>1;
				cnt = query(1, N, 1, 1, m);
				if(m-cnt<1) l = m+1;
				else r = m;
			}
			printf("%d\n", l);
			update(1, N, 1, 1, to, 1);
		} else {
			scanf("%d", &b);
			if(a+b-1>N) continue;
			update(1, N, 1, a, a+b-1, 0);
		}
	}

	return 0;
}





