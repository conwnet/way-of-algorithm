#include <stdio.h>
#include <math.h>

int main()
{
        double n, p;

        while(~scanf("%lf%lf", &n, &p)) {
                printf("%lg\n", pow(p, 1/n));
        }

        return 0;
}
