#include <stdio.h>
#include <string.h>

int arr[500];

int main()
{
        int T, a, b, i, N;

        scanf("%d", &T);
        while(T--) {
                memset(arr, 0, sizeof(arr));
                scanf("%d", &N);
                while(N--) {
                        scanf("%d%d", &a, &b);
                        for(i=a; i<=b; i++) arr[i]++;
                }
                int maxn = 0;
                for(i=0; i<=400; i++)
                        if(arr[i]>maxn) maxn = arr[i];
                printf("%d\n", maxn*10);
        }

        return 0;
}
