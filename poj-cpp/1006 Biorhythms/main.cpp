#include <stdio.h>

int main()
{
    int p, e, i, d, a, c = 1;

    while(scanf("%d%d%d%d", &p, &e, &i, &d) && p >= 0) {
        for(a = d + 1; ; a++) {
            if((a - p) % 23 == 0 &&
                (a - e) % 28 == 0 &&
                (a - i) % 33 == 0)
                break;
        }
        printf("Case %d: the next triple peak occurs in %d days.\n", c++, a - d);
    }

    return 0;
}
