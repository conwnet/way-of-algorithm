#include <stdio.h>
#include <string.h>

int bit[1100][1100];
int S;

inline int lowbit(int x)
{
	return x&-x;
}

void Add(int r, int c, int x)
{
	int t = c;
	while(r<=S) {
		c = t;
		while(c<=S) {
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
	int op, a, b, c, d;

	scanf("%d%d", &op, &S);
	memset(bit, 0, sizeof(bit));
	while(scanf("%d", &op)) {
		if(3==op) break;
		if(1==op) {
			scanf("%d%d%d", &a, &b, &c);
			Add(a+1, b+1, c);
		} else if(2==op) {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			int aa = Sum(a, b);
			int dd = Sum(c+1, d+1);
			int bb = Sum(a, d+1);
			int cc = Sum(c+1, b);
			printf("%d\n", dd+aa-bb-cc);
		}
	}

	return 0;
}









