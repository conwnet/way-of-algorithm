#include <stdio.h>

int main()
{
        int a, b, c, d, e, f;

        while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f)) {
                if(!a && !b && !c && !d && !e && !f) break;
                printf("%g\n", (a+b+c+d+e+f)/6.0);
        }

        return 0;
}
