#include <stdio.h>

int main()
{
    int T;
    double x, y;

    scanf("%d", &T);
    for(int nC = 1; nC <= T; nC++) {
        scanf("%lf%lf", &x, &y);
        double s = (x * x + y * y) * 3.1415926535d;
        int ans = (s / 100) + 1;
        printf("Property %d: This property will begin eroding in year %d.\n", nC, ans);
    }
    printf("END OF OUTPUT.");

    return 0;
}
