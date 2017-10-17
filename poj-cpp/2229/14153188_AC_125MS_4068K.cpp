#include <stdio.h>
#include <string.h>

int arr[1100000];

int main()
{
        int i, n;

        scanf("%d", &n);
        arr[1] = 1;
        for(i=2; i<=n; i++) {
                arr[i] = (arr[i-1] + (i%2?0:arr[i/2]))%1000000000;
        }
        printf("%d\n", arr[n]);

        return 0;
}
