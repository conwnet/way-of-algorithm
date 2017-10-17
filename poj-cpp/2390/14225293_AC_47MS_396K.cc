#include <stdio.h>

int main()
{
        int R, Y;
        double M;

        scanf("%d%lf%d", &R, &M, &Y);
        while(Y--) M *= (1+R/100.0);
        printf("%d\n", (int)M);

        return 0;
}
