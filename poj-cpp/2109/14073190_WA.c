#include <stdio.h>
#include <math.h>

int main()
{
        double n, p;

        while(~scanf("%lf%lf", &n, &p)) {
                printf("%d\n", (int)pow(p, 1/n));
        }

     //   printf("%lld", );
        return 0;
}