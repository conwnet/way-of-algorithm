#include <stdio.h>
#include <string.h>
#include <math.h>

double R;
const double PI = acos(-1);
int n;

int is_ok(double r)
{
        double theta = (n-2)*PI / 2 / n;
        return r/cos(theta) < R-r;

}

int main()
{
        int T;

        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%lf%d", &R, &n);
                double l = 0; double r = R;
                while(r-l > 1e-6) {
                        double m = (l+r) / 2;
                        if(is_ok(m)) l = m;
                        else r = m;
                }
                printf("Scenario #%d:\n", nC);
                printf("%.3f\n\n", l);
        }

        return 0;
}