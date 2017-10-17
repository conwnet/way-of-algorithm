#include <stdio.h>
#include <string.h>

int main()
{
        int T, n, a, b, c, d;

        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%d", &n);
                a = n/25; n %= 25;
                b = n/10; n %= 10;
                c = n/5; n %= 5;
                d = n;
                printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n", nC, a, b, c, d);
        }

        return 0;
}
