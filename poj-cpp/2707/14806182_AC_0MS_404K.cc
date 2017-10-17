#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int L, R, l, r;

        while(scanf("%d%d%d%d", &L, &R, &l, &r)) {
                if(!L && !R && !l && !r) break;
                double d = min((double)l/L, (double)r/R);
                d = max(d, min((double)l/R, (double)r/L));
                if(d>1) d = 1;
                printf("%d%%\n", (int)(d*100));
        }

        return 0;
}
