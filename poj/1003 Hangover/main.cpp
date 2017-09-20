#include <stdio.h>

int main()
{
    double d;

    while(scanf("%lf", &d) && d > 0.001) {
        int n = 2;
        double s = 0;
        while(s < d)
            s += 1.0 / n++;
        printf("%d card(s)\n", n - 2);
    }
    
    return 0;
}
