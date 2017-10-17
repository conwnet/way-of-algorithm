#include <stdio.h>

typedef long long ll;

void gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
        if(!b) { d = a; x = 1; y = 0; }
        else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main()
{
        ll a, b, c, d, x, y;
        while(scanf("%lld%lld%lld%lld", &a, &b, &c, &d)) {
                if(!a && !b && !c && !d) break;
                ll m = (ll)1<<d;
                b = b-a;
                a = c;
                gcd(a, m, d, x, y);
                if(b%d) printf("FOREVER\n");
                else {
                        x = x*(b/d) % m;
                        x = (x+m/d) % (m/d);
                        printf("%lld\n", x);
                }
        }

        return 0;
}




