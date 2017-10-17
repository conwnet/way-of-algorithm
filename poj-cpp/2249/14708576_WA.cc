#include <stdio.h>
#include <string.h>

long long cal(int n, int m)
{
        if(n-m < m) m = n-m;
        long long a = 1;
        for(int i=0; i<m; i++)
                a *= (n-i);
        long long b = 1;
        for(int i=1; i<=m; i++)
                b *= i;
        return a/b;
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
