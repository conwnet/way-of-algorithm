#include <stdio.h>
#include <math.h>

int N, F, ri[10010];
const double PI = acos(-1.0);

int cal(double s)
{
        int sum = 0;
        for(int i=0; i<N; i++) {
                sum += ri[i]*ri[i]*PI / s;
        }
        return sum;
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &F);
                for(int i=0; i<N; i++)
                        scanf("%d", &ri[i]);
                double l = 0, r = 10010;
                while(r-l > 1e-5) {
                        double m = (l+r)/2;
                        if(cal(m)<F+1) r = m;
                        else l = m;
                }
                printf("%.4f\n", l);
        }

        return 0;
}
