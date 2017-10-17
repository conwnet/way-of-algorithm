#include <stdio.h>
#include <stdlib.h>

void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y);

int main()
{
        long long x, y, m, n, L, a, b, d, t, tt;

        while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L)) {
              //  if(m-n<0) m^=n^=m^=n, x^=y^=x^=y;
                ex_gcd(n-m, L, d, a, b);
                if((x-y)%d) {
                        printf("Impossible\n");
                        continue;
                } else {
                        a *= (x-y)/d;
                        long long k = a*d/L;
                        k = a-k*L/d;
                        if(k<0) k += L/d;
                        printf("%lld\n", k);

                }
        }

        return 0;
}

void ex_gcd(long long a, long long b, long long &d, long long &x, long long &y)
{
        if(!b) {
                d = a;
                x = 1;
                y = 0;
        } else {
                ex_gcd(b, a%b, d, y, x);
                y -= x*(a/b);
        }

}
