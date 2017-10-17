#include <stdio.h>
#include <string.h>

int sum[305];
int wei[305];

int main()
{
        int T, n;

        sum[0] = 0;
        for(int i=1; i<=301; i++)
                sum[i] = i + sum[i-1];
        for(int i=1; i<=300; i++)
                wei[i] = wei[i-1] + i*sum[i+1];

        scanf("%d", &T);
        for(int nCase=1; nCase<=T; nCase++) {
                scanf("%d", &n);
                printf("%d %d %d\n", nCase, n, wei[n]);
        }

        return 0;
}
