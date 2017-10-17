#include <stdio.h>

int main()
{
        int a, b, c, d;

        while(scanf("%d%d%d%d", &a, &b, &c, &d)) {
                if(!a && !b && !c && !d) break;
                printf("%d\n", c-b+a);
        }

        return 0;
}