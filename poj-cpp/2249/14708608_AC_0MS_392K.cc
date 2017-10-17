#include <stdio.h>
#include <string.h>

int vst[100];

long long cal(int n, int m)
{
        memset(vst, 0, sizeof(vst));
        if(n-m < m) m = n-m;
        long long a = 1;
        for(int i=0; i<m; i++) {
                a *= (n-i);
                for(int j=2; j<=m; j++) {
                        if(!vst[j] && !(a%j)) {
                                vst[j] = 1;
                                a /= j;
                        }
                }
        }
        return a;
}

int main()
{
        int n, m;

        while(scanf("%d%d", &n, &m)) {
                if(!n && !m) break;
                printf("%lld\n", cal(n, m));
        }

        return 0;
}
