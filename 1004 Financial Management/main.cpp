#include <stdio.h>

int main()
{
    double mon, sum = 0;

    while(~scanf("%lf", &mon))
        sum += mon;
    printf("$%.2f", sum / 12);

    return 0;
}
