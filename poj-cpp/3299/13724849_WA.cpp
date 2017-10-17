#include <cstdio>
#include <cstring>
#include <cmath>

#define exp(x) pow(2.718281828, (x))

int main(){
    double t, d, h, e;
    char input[30];

    while(gets(input)){
        if(0==strcmp(input, "E")) return 0;
        sscanf(input, "T %lf D %lf", &t, &d);
        e = 6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
        h = (0.5555)*(e-10.0);
        printf("T %.1lf D %.1lf H %.1lf\n", t, d, t+h);
    }

    return 0;
}
