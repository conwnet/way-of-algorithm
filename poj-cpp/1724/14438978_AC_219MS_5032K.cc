#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
        int to, dis, cost;
};

vector<Edge> G[110];
int dp[110][10010];
int used[110];
int K, N, R, ans;

int dfs(int s, int cost, int dis)
{
        if(cost>K) return 0;
        if(dis>ans) return 0;
        if(dis>dp[s][cost]) return 0;
        if(s==N) {
                ans = min(ans, dis);
                return 0;
        }
        dp[s][cost] = dis;
        for(int i=0; i<G[s].size(); i++) {
                if(used[G[s][i].to]) continue;
                used[G[s][i].to] = 1;
                dfs(G[s][i].to, cost+G[s][i].cost, dis+G[s][i].dis);
                used[G[s][i].to] = 0;
        }

}

int main()
{
        int s, t, l, c;

        scanf("%d%d%d", &K, &N, &R);
        for(int i=0; i<R; i++) {
                scanf("%d%d%d%d", &s, &t, &l, &c);
                if(s!=t)
                        G[s].push_back((Edge){t, l, c});
        }
        memset(used, 0, sizeof(used));
        for(int i=0; i<110; i++)
                for(int j=0; j<10010; j++)
                        dp[i][j] = 1<<30;
        used[1] = 1;
        ans = 1<<30;
        dfs(1, 0, 0);
        if(ans<(1<<30))
                printf("%d\n", ans);
        else printf("-1\n");

        return 0;
}
