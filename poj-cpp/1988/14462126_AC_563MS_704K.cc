#include <stdio.h>
#include <string.h>

int p[30005], under[30005], sum[30005];

int findp(int x)
{
	if(x==p[x]) return x;
	else {
		int t = findp(p[x]);
		under[x] += under[p[x]];
		return p[x] = t;
	}
}

int main()
{
	int P, a, b;
	char op;
	
	for(int i=0; i<30005; i++) {
		p[i] = i;
		under[i] = 0;
		sum[i] = 1;
	}
	scanf("%d", &P);
	while(P--) {
		getchar();
		scanf("%c %d", &op, &a);
		if(op=='M') {
			scanf("%d", &b);
			int x = findp(a);
			int y = findp(b);
			p[x] = y;
			under[x] += sum[y];
			sum[y] += sum[x];
			sum[x] = 0;
		} else {
			findp(a);
			printf("%d\n", under[a]);
		}
		//for(int i=1; i<=6; i++) printf("%d ", under[i]); printf("\n");
		//for(int i=1; i<=6; i++) printf("%d ", sum[i]);printf("\n");
		//for(int i=1; i<=6; i++) printf("%d ", p[i]);printf("\n"); printf("\n");

	}

	return 0;
}