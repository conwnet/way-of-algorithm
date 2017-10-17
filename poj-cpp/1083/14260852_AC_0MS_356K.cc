#include <stdio.h>
#include <string.h>

int arr[201];

int main()
{
        int T, a, b, i, N;

        scanf("%d", &T);
        while(T--) {
                memset(arr, 0, sizeof(arr));
                scanf("%d", &N);
                while(N--) {
                        scanf("%d%d", &a, &b);
                        if(a>b) a^=b^=a^=b;
                        a = (a+1)>>1; b = (b+1)>>1;
                        for(i=a; i<=b; i++) arr[i]++;
                }
                int maxn = 0;
                for(i=0; i<=200; i++)
                        if(arr[i]>maxn) maxn = arr[i];
                printf("%d\n", maxn*10);
        }

        return 0;
}
