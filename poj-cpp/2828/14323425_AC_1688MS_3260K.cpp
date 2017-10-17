#include <stdio.h>
#include <string.h>

int bit[200005], N, val[200005], p[200005], v[200005];

int lowbit(int x)
{
	return x&(-x);
}

void Add(int pos, int n)
{
	while(pos<=N) {
		bit[pos] += n;
		pos += lowbit(pos);
	}
}

int Sum(int pos)
{
	int s;

	s = 0;
	while(pos>0) {
		s += bit[pos];
		pos -= lowbit(pos);
	}

	return s;
}

int main()
{
	int i;

	while(~scanf("%d", &N)) {
		memset(bit, 0, sizeof(bit));
		for(i=2, bit[1]=0; i<=N; i++) Add(i, 1);
		for(i=0; i<N; i++) scanf("%d%d", &p[i], &v[i]);
		for(i=N-1; i>=0; i--) {
			int l=1, r=N;
			while(l<r) {
				int mid = (l+r)>>1;
				if(Sum(mid)<p[i]) l = mid+1;
				else r = mid;
			}
			Add(l, -1);
			val[l] = v[i];
		}
		printf("%d", val[1]);
		for(i=2; i<=N; i++) printf(" %d", val[i]);
		printf("\n");
	}

	return 0;
}

