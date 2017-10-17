#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[101][10001];
int maps[101][101];
int cost[101][101];
int used[101];
int K, N, R, ans;

int dfs(int s, int c, int dis)
{
        int i, j, tmp;

        if(dp[s][c]) return dp[s][c];
        if(c>K) return 0;
        if(s==N) {
                return maps[s][c] = ans = min(ans, dis);
        }
        for(i=1; i<=N; i++) {
                if(used[i] || maps[s][i]==-1) continue;
                used[i] = 1;
                tmp = dfs(i, c+cost[s][i], dis+maps[s][i]);
                used[i] = 0;
        }
        return dp[s][c] = min(dp[s][c], tmp);
}

int main()
{
        int s, t, l, c;

        scanf("%d%d%d", &K, &N, &R);
        memset(maps, -1, sizeof(maps));
        memset(cost, 0, sizeof(cost));
        memset(used, 0, sizeof(used));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<R; i++) {
                scanf("%d%d%d%d", &s, &t, &l, &c);
                maps[s][t] = l;
                cost[s][t] = c;
        }
        ans = 1<<30;
        dfs(1, 0, 0);
        printf("%d\n", ans);

        return 0;
}
