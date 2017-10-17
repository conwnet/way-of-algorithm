#include <stdio.h>
#include <math.h>

const int INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
        long long a, b, c, B, C;

        while(~scanf("%lld", &a)) {
                long long ans = INF;
                for(b=1; ; b++) {
                        if(a!=b && 0==(a*b+1)%(b-a)) {
                                c = (a*b+1)/(b-a);
                                if(c<0) continue;
                                if(b+c<ans) {
                                        ans = b+c;
                                        B = b;
                                        C = c;
                                }
                                if(b>c) break;
                        }
                }
                printf("%lld\n", ans);
        }

        return 0;
}
