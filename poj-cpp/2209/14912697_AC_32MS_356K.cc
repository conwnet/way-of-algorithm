#include <stdio.h>

int pow(int x, int n)
{
        int s = 1;
        while(n) {
                if(n&1) s *= x;
                x *= x;
                n >>= 1;
        }
        return s;
}

int main()
{
        int n, ans, e, x;
        ans = 0;
        scanf("%d%d", &n, &e);
        while(n--) {
                scanf("%d", &x);
                x = pow(x, e);
                if(x > 0) ans += x;
        }
        printf("%d\n", ans);

        return 0;
}
