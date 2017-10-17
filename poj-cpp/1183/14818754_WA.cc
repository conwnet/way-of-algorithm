#include <stdio.h>
#include <math.h>

const int INF = 0x3f3f3f3f;

int main()
{
        int a, b, c;

        while(~scanf("%d", &a)) {
                int ans = INF;
                for(b=1; ; b++) {
                        if(a!=b && 0==(a*b+1)%(b-a)) {
                                c = (a*b+1)/(b-a);
                                if(c<0) continue;
                                if(b+c<ans) { ans = b+c; break; }
                                if(b>c) break;
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}
