#include <stdio.h>
#include <string.h>
#include <math.h>

double arr[8000000];

int solve(int n);

int main()
{
        int T, n;

        scanf("%d", &T);
        memset(arr, 0, sizeof(arr));
        solve(7999999);
        while(T--) {
                scanf("%d", &n);
                printf("%d\n", (int)arr[n]);
        }

        return 0;
}

int solve(int n)
{
        int ans, i;

        arr[0] = 1;
        for(i=1; i<=n; i++) {
                arr[i] = log10(i)+arr[i-1];
        }
}

