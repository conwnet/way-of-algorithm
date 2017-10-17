#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[1000001];

int solve(int n);

int main()
{
        int T, n;

        scanf("%d", &T);
        memset(arr, 0, sizeof(arr));
        solve(10000000);
        while(T--) {
                scanf("%d", &n);
                printf("%d\n", arr[n]+1);
        }

        return 0;
}

int solve(int n)
{
        int ans, i;
        double t, prev = 0;

        for(i=1; i<=n; i++) {
                t = log10(i)+prev;
                arr[i] = t;
                prev = t;
        }
}

