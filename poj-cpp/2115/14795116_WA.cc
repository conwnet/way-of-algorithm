#include <stdio.h>

void gcd(int a, int b, int &d, int &x, int &y)
{
        if(!b) { d = a; x = 1; y = 0; }
        else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int main()
{
        int a, b, c, d, k, x, y;
        while(scanf("%d%d%d%d", &a, &b, &c, &d)) {
                if(!a && !b && !c && !d) break;
                int m = 1<<d;
                b = b-a;
                a = c;
                gcd(a, m, d, x, y);
                if(b%d) printf("FOREVER\n");
                else {
                        x = x*(b/d) % m;
                        x = (x+m/d) % (m/d);
                        printf("%d\n", x);
                }
        }

        return 0;
}




