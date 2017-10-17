#include <stdio.h>
#include <math.h>

int main()
{
        int B, N;

        while(scanf("%d%d", &B, &N)) {
                if(B==0 && N==0) break;
                int l = floor(pow(B, 1.0/N));
                int r = l+1;
                if(fabs(pow(l, N)-B) < fabs(pow(r, N)-B)) {
                        printf("%d\n", l);
                } else {
                        printf("%d\n", r);
                }
        }

        return 0;
}
