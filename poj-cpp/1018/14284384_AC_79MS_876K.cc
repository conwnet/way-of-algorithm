#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[128][1024];

int main()
{
        int T, N, i, j, n, pn, b, p, maxf;
        double maxs;

        scanf("%d", &T);
        while(T--) {
                for(i=0; i<128*1024; i++) dp[0][i] = 99999999;
                scanf("%d%d", &N, &pn);
                for(i=0; i<pn; i++) { scanf("%d%d", &b, &p); dp[0][b] = p; }
                for(i=1; i<N; i++) {
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d%d", &b, &p);
                                for(j=0; j<1024; j++) {
                                        dp[i][min(b, j)] = min(dp[i][min(b, j)], dp[i-1][j]+p);
                                }
                        }
                }
                for(i=0, maxs=0; i<1024; i++) {
                        double t = (double)i/dp[N-1][i];
                        if(t>maxs) maxs = t;
                }
                printf("%.3f\n", maxs);
        }

        return 0;
}
