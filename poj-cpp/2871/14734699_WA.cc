#include <stdio.h>

int main()
{
        double p, q;

        scanf("%lf", &p);
        while(scanf("%lf", &q)) {
                if(p==999) break;
                printf("%lg\n", q-p);
                p = q;
        }
        printf("End of Output\n");

        return 0;
}
