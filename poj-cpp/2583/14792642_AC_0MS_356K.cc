#include <stdio.h>

int f(int a, int b, int c, int x)
{
        return a*x*x + b*x + c;
}

int main()
{
        int x, y, z;

        while(~scanf("%d%d%d", &x, &y, &z)) {
                int a = (x-2*y+z) / 2;
                int b = y - a - x;
                int c = x;
                printf("%d ", f(a, b, c, 3));
                printf("%d ", f(a, b, c, 4));
                printf("%d\n", f(a, b, c, 5));
        }

        return 0;
}
