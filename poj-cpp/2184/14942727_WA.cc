#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxv = 40;
const int mid = 20;
int dp[2][maxv+10], N, cow[2][128];


int main()
{
        int p;
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
                scanf("%d%d", &cow[0][i], &cow[1][i]);
        for(int i=1; i<=N; i++) {
                if(i&1) p = 1; else p = 0;
                for(int j=0; j<mid; j++) {
                        dp[p][j+mid] = max(dp[p^1][j+mid], dp[p^1][j-cow[0][i]+mid]
                                       +cow[0][i]+cow[1][i]);
                }
        }
        if(N&1) p = 1; else p = 0;
        int ans = 0;
        for(int i=mid; i<maxv; i++) {
                ///if(dp[p][i]) printf("%d %d\n", i-mid, dp[p][i]);
                if(dp[p][i]+mid>=i) ans = max(ans, dp[p][i]);
        }
        printf("%d\n", ans);

        return 0;
}
