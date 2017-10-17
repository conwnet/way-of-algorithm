#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

double get(int h, int t);

int main()
{
        int N, H, R, T, C, i, j;
        double arr[110];

        scanf("%d", &C);
        while(C--) {
                scanf("%d%d%d%d", &N, &H, &R, &T);
                for(i=0; i<N; i++) {
                        arr[i] = get(H, T-i)+2*i*R/100.0;
                }
                sort(arr, arr+N);
                printf("%.2lf", arr[0]);
                for(i=1; i<N; i++) {
                        printf(" %.2lf", arr[i]);
                }
                printf("\n");
        }

        return 0;
}

double get(int h, int t)
{
        double ot = sqrt(2.0*h/10);
        int n = t/ot;
        double lt = t-(n*ot);

        if(n&1) lt = ot-lt;
        return h-5*lt*lt;
}
