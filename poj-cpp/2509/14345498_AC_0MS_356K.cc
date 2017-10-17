#include <stdio.h>

int main()
{
        int ans, N, k, butt;

        while(~scanf("%d%d", &N, &k)) {
                ans = 0;
                butt = 0;
                while(N>0) {
                        ans += N;
                        butt += N;
                        N = butt/k;
                        butt %= k;
                }
                printf("%d\n", ans);
        }

        return 0;
}
