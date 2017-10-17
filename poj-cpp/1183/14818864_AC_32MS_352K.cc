#include <stdio.h>
#include <math.h>

const int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
        long long a, m, n;

        while(~scanf("%lld", &a)) {
                for(m=a; ; m--) {
                        if(0==(a*a+1)%m)
                                break;
                }
                n = (a*a+1) / m;
                printf("%lld\n", 2*a+m+n);
        }

        return 0;
}
