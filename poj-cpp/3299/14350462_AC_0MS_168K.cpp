#include <stdio.h>
#include <math.h>

double e2h(double e)
{
        return 0.5555*(e-10.0);
}

double D2e(double D)
{
        return 6.11*exp(5417.7530*((1/273.16)-(1/(D+273.16))));
}

double e2D(double e)
{
        return (1/(1/273.16-log(e/6.11)/5417.7530))-273.16;
}

int main()
{
        double H, D, T, h, e;
        char cmd[5];

        while(scanf("%s", cmd) && cmd[0]!='E') {
                T = D = H = -99999;
                if(cmd[0]=='T') scanf("%lf", &T);
                else if(cmd[0]=='D') scanf("%lf", &D);
                else scanf("%lf", &H);
                scanf("%s", cmd);
                if(cmd[0]=='T') scanf("%lf", &T);
                else if(cmd[0]=='D') scanf("%lf", &D);
                else scanf("%lf", &H);
                if(D>-9999) {
                        h = e2h(D2e(D));
                        if(T<-9999) T = H-h;
                        else H = T+h;
                }
                else {
                        h = H - T;
                        e = h/0.5555 + 10.0;
                        D = e2D(e);
                }
                printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);
        }

        return 0;
}
