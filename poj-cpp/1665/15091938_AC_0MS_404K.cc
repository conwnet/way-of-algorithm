#include <stdio.h>
#include <math.h>

const double pi = acos(-1.0);

int main()
{
        double d, t;
        int n, nC = 0;
        while(~scanf("%lf%d%lf", &d, &n, &t)) {
                if(!n) break;
                double c = d * pi;
                double s = c * n / (12 * 5280);
                double v = s * 3600 / t;
                printf("Trip #%d: %.2f %.2f\n", ++nC, s, v);
        }

        return 0;
}
