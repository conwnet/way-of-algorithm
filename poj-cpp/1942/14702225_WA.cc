#include <stdio.h>

long long arr[1000000];

int main()
{
        int n, m;

        while(scanf("%d%d", &n, &m)) {
                if(!n && !m) break;
                if(n>m) n^=m^=n^=m;
                if(n<=1) {
                        printf("%d\n", n);
                        continue;
                } else if(n==2) {
                        printf("%d\n", m);
                        continue;
                }

                for(int i=1; i<1000000; i++)
                        arr[i] = (long long)i*(i+1)/2;
                for(int i=3; i<n; i++) {
                        for(int i=2; i<=m; i++)
                                arr[i] = arr[i-1] + arr[i];
                }
                printf("%lld\n", arr[m]);
        }

        return 0;
}
