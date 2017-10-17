#include <stdio.h>
#include <string.h>

int N, arr[55];

int main()
{
        for(int nCase=1; scanf("%d", &N) && N; nCase++) {
                int sum = 0;
                for(int i=0; i<N; i++) {
                        scanf("%d", &arr[i]);
                        sum += arr[i];
                }
                sum /= N;
                int ans = 0;
                for(int i=0; i<N; i++) {
                        if(arr[i]>sum)
                                ans += arr[i]-sum;
                }
                printf("Set #%d\n", nCase);
                printf("The minimum number of moves is %d.\n", ans);
        }

        return 0;
}
