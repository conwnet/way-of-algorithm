#include <stdio.h>
#include <string.h>

int arr[32], N, sum;

int main()
{
        while(scanf("%d", &N) && N) {
                sum = 0;
                for(int i=0; i<N; i++) {
                        scanf("%d", &arr[i]);
                        sum += arr[i];
                }
                int cnt = 0, i;
                for(i=0; cnt<sum/2; i++)
                        cnt += arr[i];
                if(sum&1 || cnt!=sum/2) {
                        printf("No equal partitioning.\n");
                } else {
                        printf("Sam stops at position %d and Ella stops at position %d.\n", i, i+1);
                }
        }

        return 0;
}
