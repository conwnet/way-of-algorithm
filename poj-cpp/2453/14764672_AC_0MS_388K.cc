#include <stdio.h>

int main()
{
        int n;

        while(~scanf("%d", &n) && n) {
                int a = n + (n&-n);
                int b = (a|n) - a;
                b &= b<<1;
                while(b && !(b&1)) b >>= 1;
                printf("%d\n", a+b);
        }

        return 0;
}

