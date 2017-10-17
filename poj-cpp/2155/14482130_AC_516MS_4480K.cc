#include <stdio.h>
#include <string.h>

int N, bit[1024][1024];

inline int lowbit(int x)
{
	return x&-x;
}

void Add(int r, int c, int x)
{
	int t = c;
	while(r<=N) {
		c = t;
		while(c<=N) {
			bit[r][c] += x;
			c += lowbit(c);
		}
		r += lowbit(r);
	}
}

int Sum(int r, int c)
{
	int sum = 0;
	int t = c;
	while(r>0) {
		c = t;
		while(c>0) {
			sum += bit[r][c];
			c -= lowbit(c);
		}
		r -= lowbit(r);
	}
	return sum;
}

int main()
{
	int Q, op, a, b, c, d, T;

	scanf("%d", &T);
	while(T--) {
		memset(bit, 0, sizeof(bit));
		scanf("%d%d", &N, &Q);
		while(Q--) {
			getchar();
			op = getchar();
			if(op=='C') {
				scanf("%d%d%d%d", &a, &b, &c, &d);
				Add(a, b, 1);
				Add(c+1, d+1, 1);
				Add(a, d+1, -1);
				Add(c+1, b, -1);
			} else {
				scanf("%d%d", &a, &b);
				printf("%d\n", Sum(a, b)&1);
			}
		}
		printf("\n");
	}

	return 0;
}








