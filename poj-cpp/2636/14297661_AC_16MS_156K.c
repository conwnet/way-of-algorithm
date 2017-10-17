#include <stdio.h>

int main()
{
	int i, N, T, sum, n;
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		sum = 0;
		for(i=0; i<N; i++) {
			scanf("%d", &n);
			sum += n;
		}
		printf("%d\n", sum-N+1);
	}

	return 0;
}