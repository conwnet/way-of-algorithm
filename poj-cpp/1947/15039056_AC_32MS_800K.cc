#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 350;
vector<int> G[maxn];
int N, P, dp[maxn][maxn];

int dfs(int u, int pa)
{
        memset(dp[u], 0x3f, sizeof(dp[u]));
        dp[u][1] = 0;
        for(int i=0; i<G[u].size(); i++) {
                int v = G[u][i];
                if(v==pa) continue;
                dfs(v, u);
                for(int j=P; j>=1; j--) {
                        int t = dp[u][j]+1;
                        for(int k=1; k<j; k++)
                                t = min(t, dp[u][k]+dp[v][j-k]);
                        dp[u][j] = t;
                }
        }
}

int main()
{
        int u, v;
        scanf("%d%d", &N, &P);
        for(int i=1; i<N; i++) {
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
        }
        dfs(1, -1);
        int ans = dp[1][P];
        for(int i=2; i<=N; i++)
                ans = min(ans, dp[i][P]+1);
        printf("%d\n", ans);

        return 0;
}

