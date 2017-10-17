#include <stdio.h>

long long arr[1000000];

int main()
{
        long long n, m;

        while(scanf("%lld%lld", &n, &m)) {
                if(!n && !m) break;
                m++; n++;
                if(n>m) n^=m^=n^=m;
                if(n<=1) {
                        printf("%lld\n", n);
                        continue;
                } else if(n==2) {
                        printf("%lld\n", m);
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
