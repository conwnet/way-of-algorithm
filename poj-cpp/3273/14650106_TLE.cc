#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
const int maxn = 100005;
int dp[maxn][2];
int sum[maxn];
int N, M;

int main()
{
        int t;
        sum[0] = 0;
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) {
                scanf("%d", &t);
                sum[i] = sum[i-1] + t;
        }
        for(int i=1; i<=N; i++)
                dp[i][1] = sum[i];
        for(int i=2; i<=M; i++) {
                for(int j=i; j<=N-M+i; j++) {
                        int ans = INF;
                        for(int k=i-1; k<j; k++) {
                                int tmp = max(dp[k][(i-1)&1], sum[j]-sum[k]);
                                ans = min(ans, tmp);
                        }
                        dp[j][i&1] = ans;
                }
        }
        printf("%d\n", dp[N][M&1]);

        return 0;
}





