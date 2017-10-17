#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxv = 100010;
const int mid = 150000;
int dp[2][maxv*3], N, cow[2][128];
const int INF = 0xbfbfbfbf;

int main()
{
        int p;
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%d%d", &cow[0][i], &cow[1][i]);
        }
        memset(dp, 0xbf, sizeof(dp)); dp[0][mid] = 0;
        for(int i=1; i<=N; i++) {
                if(i&1) p = 1; else p = 0;
                for(int j=-maxv; j<maxv; j++) {
                        //if(dp[p^1][j+mid]==-INF && dp[p^1][j-cow[0][i]+mid]==INF)
                        dp[p][j+mid] = max(dp[p^1][j+mid],
                                dp[p^1][j-cow[0][i]+mid]+cow[0][i]+cow[1][i]);
                }

        }
        if(N&1) p = 1; else p = 0;
        int ans = 0;
        for(int i=mid; i<maxv*3; i++) {
                //if(dp[p][i]+mid>=i) printf("%d %d\n", i-mid, dp[p][i]);
                if(dp[p][i]+mid>=i) ans = max(ans, dp[p][i]);
        }
        printf("%d\n", ans);

        return 0;
}
