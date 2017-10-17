#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[60], N;

int main()
{
	int i, j, ave, ans, sum, tmp, nCase = 0;

	while(scanf("%d", &N) && N) {
		printf("Set #%d\n", ++nCase);
		printf("The minimum number of moves is ");
		sum = 0;
		for(i=0; i<N; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		sort(arr, arr+N);
		ave = sum;
		for(ave=1; ave<=sum; ave++) {
			if(sum%ave==0) {
				tmp = 0;
				i = N-sum/ave;
				for(j=0; j<i; j++) tmp += arr[j];
				if(i<0) i = 0;
				for( ; i<N; i++) {
					if(arr[i]>ave)
						tmp += arr[i]-ave;
				}
				if(tmp<ans) ans = tmp;
			}
		}
		printf("%d.\n", ans);
	}

	return 0;
}



