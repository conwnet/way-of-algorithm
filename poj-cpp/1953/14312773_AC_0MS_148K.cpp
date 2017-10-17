#include <stdio.h>

int main()
{
        int T, nCase, n, i, arr[45];

        arr[0] = 1; arr[1] = 2;
        for(i=2; i<45; i++) arr[i] = arr[i-1]+arr[i-2];
        scanf("%d", &T);
        for(nCase=1; nCase<=T; nCase++) {
                scanf("%d", &n);
                printf("Scenario #%d:\n%d\n\n", nCase, arr[n]);
        }

        return 0;
}
