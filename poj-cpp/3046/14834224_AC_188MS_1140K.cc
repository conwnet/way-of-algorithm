#include <stdio.h>
#include <string.h>

const int maxn = 100005;
const int MOD = 1000000;
int dp[2][maxn], T, A, S, B, cnt[maxn];

int main()
{
        int a;
        scanf("%d%d%d%d", &T, &A, &S, &B);
        while(A--) {
                scanf("%d", &a);
                cnt[a]++;
        }
        int cc = 0;
        dp[0][0] = 1;
        for(int i=1; i<=T; i++) {
                int y = i&1; int x = y^1;
                memcpy(dp[y], dp[x], sizeof(dp[x]));
                for(int j=0; j<=cc; j++) {
                        for(int k=1; k<=cnt[i]; k++) {
                                dp[y][j+k] += dp[x][j];
                                dp[y][j+k] %= MOD;
                        }
                }
                cc += cnt[i];
        }
        int ans = 0;
        for(int i=S; i<=B; i++) {
                ans += dp[T&1][i];
                ans %= MOD;
        }
        printf("%d\n", ans);

        return 0;
}
