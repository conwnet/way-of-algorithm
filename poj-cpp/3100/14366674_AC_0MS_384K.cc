#include <stdio.h>
#include <math.h>

int main()
{
        int B, N;

        while(scanf("%d%d", &B, &N)) {
                if(B==0 && N==0) break;
                int m = (int)(pow(B, 1.0/N)+0.5);
                int l = m-1, r = m+1;
                if(fabs(pow(l, N)-B) < fabs(pow(m, N)-B)) {
                        printf("%d\n", l);
                } else if(fabs(pow(m, N))-B < fabs(pow(r, N)-B)) {
                        printf("%d\n", m);
                } else {
                        printf("%d\n", r);
                }
        }

        return 0;
}
