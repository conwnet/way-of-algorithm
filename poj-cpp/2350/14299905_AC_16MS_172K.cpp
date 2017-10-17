#include <stdio.h>

int main()
{
	int arr[1024], N, i, sum, ans, T;

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(i=0, sum=0; i<N; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		ans = 0;
		for(i=0; i<N; i++) {
			if(arr[i]>(double)sum/N) ans++;
		}
		printf("%.3lf%%\n", (double)ans*100/N);
	}
	return 0;
}