#include <stdio.h>
#include <math.h>

const int INF = 0x3f3f3f3f;

int main()
{
        int a, b, c;

        scanf("%d", &a);
        for(b=1; ; b++) {
                if(a!=b && 0==(a*b+1)%(b-a)) {
                        c = (a*b+1)/(b-a);
                        if(c<0) continue;
                        break;
                }
        }
        printf("%d\n", b+c);

        return 0;
}
