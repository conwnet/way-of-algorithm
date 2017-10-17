#include <stdio.h>
#include <math.h>

const double PI = acos(-1.0);

int main()
{
        int D, V;
        while(scanf("%d%d", &D, &V)) {
                if(!D && !V) break;
                double R = D/2.0;
                double _l = 0, _r = R;
                double S = R * R * PI;
                while(_r-_l>0.0001) {
                        double _m = (_l+_r) / 2;
                        double s = _m * _m * PI;
                        double V1 = (R*R + _m*_m + R*_m) * (R-_m) * PI / 3;
                        double V2 = s * _m*2;
                        double v = S*D - (V1*2 + V2);
                        if(v>V) _l = _m;
                        else _r = _m;
                }
                printf("%.3f\n", _l*2);
        }

        return 0;
}
