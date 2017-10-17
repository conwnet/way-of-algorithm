#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int llen[200005], rlen[200005], len[200005];
int N, M, lazy[200005];

void push_down(int L, int R, int o)
{
	if(L!=R) {
		lazy[o*2] = lazy[o*2+1] = lazy[o];
	}
	if(lazy[o])
		llen[o] = rlen[o] = len[o] = 0;
	else llen[o] = rlen[o] = len[o] = R-L+1;
	lazy[o] = -1;
}

void update(int L, int R, int o, int l, int r, int x)
{
	if(lazy[o]!=-1)
		push_down(L, R, o);
	if(l<=L && r>=R) {
		lazy[o] = x;
		push_down(L, R, o);
		return ;
	}
	if(l>R || r<L) return ;
	int M = (L+R)>>1;
	update(L, M, o*2, l, r, x);
	update(M+1, R, o*2+1, l, r, x);
	if(llen[o*2] == M-L+1)
		llen[o] = llen[o*2]+llen[o*2+1];
	else llen[o] = llen[o*2];
	if(rlen[o*2+1] == R-M)
		rlen[o] = rlen[o*2+1]+rlen[o*2];
	else rlen[o] = rlen[o*2+1];
	len[o] = max(llen[o], rlen[o]);
	len[o] = max(len[o], rlen[o*2]+llen[o*2+1]);
}

int query(int L, int R, int o, int l)
{
	if(lazy[o]!=-1)
		push_down(L, R, o);
	int M = (L+R)>>1;
	if(len[o*2] >= l) {
		return query(L, M, o*2, l);
	} else if(rlen[o*2]+llen[o*2+1] >= l) {
		return M-rlen[o*2]+1;
	} else if(len[o*2+1] >= l) {
		return query(M+1, R, o*2+1, l);
	}
	if(llen[o] >= l) return L;
	else if(rlen[o] >= l) return R-rlen[o]+1;
	else return 0;
}

int main()
{
	int op, a, b;

	scanf("%d%d", &N, &M);
	memset(lazy, -1, sizeof(lazy));
	lazy[1] = 0;
	while(M--) {
		scanf("%d%d", &op, &a);
		if(op==1) {
			int t = query(1, N, 1, a);
			printf("%d\n", t);
			if(t>0) {
				update(1, N, 1, t, t+a-1, 1);
			}
		} else {
			scanf("%d", &b);
			update(1, N, 1, a, a+b-1, 0);
		}
	}

	return 0;
}

