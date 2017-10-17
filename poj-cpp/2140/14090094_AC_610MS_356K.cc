#include <stdio.h>
#include <math.h>

int main()
{
       int i, j, N, cnt, t;

       scanf("%d", &N);
       cnt = 0;
       for(i=1; i<=N; i++) {
                for(j=i; j<=N; j++) {
                        if((i+j)*(j-i+1)/2==N) cnt++;
                        else if((i+j)*(j-i+1)/2>N) break;
                }
       }
       printf("%d\n", cnt);

        return 0;
}
