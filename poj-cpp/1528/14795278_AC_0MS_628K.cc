#include <stdio.h>

const int maxn = 70000;
int arr[maxn];

int solve()
{
        for(int i=1; i<maxn; i++) {
                for(int j=i*2; j<maxn; j+=i)
                        arr[j] += i;
        }
}

int main()
{
        int n;
        solve();
        printf("PERFECTION OUTPUT\n");
        while(scanf("%d", &n) && n) {
                printf("%5d  ", n);
                if(n>arr[n]) printf("DEFICIENT\n");
                else if(n<arr[n]) printf("ABUNDANT\n");
                else printf("PERFECT\n");
        }
        printf("END OF OUTPUT\n");

        return 0;
}
