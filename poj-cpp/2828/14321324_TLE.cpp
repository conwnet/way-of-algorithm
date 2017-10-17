#include <stdio.h>

int val[200005], next[200005];

int main()
{
	int N, i, j, n, v, cnt;

	while(~scanf("%d", &N)) {
		cnt = 1;
		next[0] = -1;
		for(i=0; i<N; i++) {
			scanf("%d%d", &n, &v);
			val[cnt] = v;
			j = 0;
			for(int k=0; k<n; k++) {
				j = next[j];
			}
			next[cnt] = next[j];
			next[j] = cnt++;
		}
		j = next[0];
		printf("%d", val[j]);
		for(i=1; i<N; i++) {
			printf(" %d", val[j=next[j]]);
		}
		printf("\n");
	}
	
	return 0;
}
