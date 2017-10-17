#include <stdio.h>
#include <math.h>

int main()
{
        int n;
        while(~scanf("%d", &n)) {
                int l = 0; int r = 10000;
                while(l<r) {
                        int m = (l+r) >> 1;
                        if(m*(m+1)/2 < n) l = m+1;
                        else r = m;
                }
                int s;
                int res = n - (l-1)*l/2;
                if(l & 1) s = res;
                else s = l-res+1;
                printf("TERM %d IS %d/%d\n", n, l-s+1, s);
        }

        return 0;
}
