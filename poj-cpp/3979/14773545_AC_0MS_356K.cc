#include <stdio.h>

int gcd(int a, int b)
{
        return b ? gcd(b, a%b) : a;
}

int main()
{
        int a, b, c, d;
        char op;
        while(~scanf("%d/%d%c%d/%d", &a, &b, &op, &c, &d)) {
                int e = b/gcd(b, d)*d;
                a *= e/b; c *= e/d;
                if(op=='+') a += c;
                else a -= c;
                int f = gcd(a, e);
                a /= f; e /= f;
                if(e<0) {e *= -1; a *= -1;}
                if(0==a%e) printf("%d\n", a/e);
                else printf("%d/%d\n", a, e);
        }

        return 0;
}
