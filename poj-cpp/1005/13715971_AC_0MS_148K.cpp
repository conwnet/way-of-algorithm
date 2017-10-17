#include <cstdio>
#include <cmath>

#define PI 3.1416

int main(){
    double x, y, r, s;
    int nCase, day, t=0;
    scanf("%d", &nCase);
    while(nCase--){
        day = 0;
        scanf("%lf%lf", &x, &y);
        r = sqrt(x*x+y*y);
        s = PI*r*r/2;
        day = s/50;
        printf("Property %d: This property will begin eroding in year %d.\n", ++t, day+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
