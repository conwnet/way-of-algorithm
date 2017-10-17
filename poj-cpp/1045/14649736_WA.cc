#include <stdio.h>
#include <math.h>

double VS, R, C, omg;
int N;

int main()
{
        scanf("%lf%lf%lf%d", &VS, &R, &C, &N);
        while(N--) {
                scanf("%lf", &omg);
                double ans = C*R*omg*VS/sqrt(1+(C*R*omg)*(C*R*omg));
                printf("%.3lf\n", ans);
        }

        return 0;
}
