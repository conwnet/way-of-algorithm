#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
        int T, n;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &n);
                int mod = 10;
                while(n/mod) {
                        n = (n+mod*5/10) / mod * mod;
                        mod *= 10;
                }
                printf("%d\n", n);
        }

        return 0;
}
