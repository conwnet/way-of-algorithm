#include <stdio.h>
#include <string.h>

int bit[8005], N, arr[80005];

inline int lowbit(int x)
{
	return x&-x;
}

void Add(int pos, int x)
{
	while(pos<=N) {
		bit[pos] += x;
		pos += lowbit(pos);
	}
}

int Sum(int pos)
{
	int sum = 0;
	while(pos>0) {
		sum += bit[pos];
		pos -= lowbit(pos);
	}
	return sum;
}

int main()
{
	scanf("%d", &N);
	for(int i=1; i<N; i++)
		scanf("%d", &arr[i]);
	for(int i=N-1; i>=0; i--) {
		int l = 1;
		int r = N;
		while(l<r) {
			int m = (l+r)>>1;
			if(m-Sum(m)<arr[i]+1) l = m+1;
			else r = m;
		}
		arr[i] = l;
		Add(l, 1);
	}
	for(int i=0; i<N; i++)
		printf("%d\n", arr[i]);

	return 0;
}





