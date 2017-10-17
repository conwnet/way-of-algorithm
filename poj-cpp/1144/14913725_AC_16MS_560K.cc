#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 128;
vector<int> G[maxn];
int dfn[maxn], low[maxn], ti, ans, iscut[maxn];

void dfs(int u, int pa)
{
        int son = 0;
        dfn[u] = low[u] = ++ti;
        for(int i=0; i<G[u].size(); i++) {
                int v = G[u][i];
                if(v==pa) continue;
                if(!dfn[v]) {
                        son++;
                        dfs(v, u);
                        if(low[v]<low[u]) low[u] = low[v];
                        if(dfn[u]<=low[v] && pa!=-1 && !iscut[u]) {
                                iscut[u] = 1; ans++;
                        }
                } else if(dfn[v]<low[u])
                        low[u] = dfn[v];
        }
        if(pa==-1 && son>1 && !iscut[u]) { iscut[u] = 1; ans++; }
}

int N;
int main()
{
        int u, v;
        while(scanf("%d", &N) && N) {
                for(int i=1; i<=N; i++) G[i].clear();
                while(1) {
                        scanf("%d", &u);
                        if(!u) break;
                        while(scanf("%d", &v)) {
                                G[u].push_back(v);
                                G[v].push_back(u);
                                if(getchar()=='\n') break;
                        }
                }
                ans = ti = 0;
                memset(dfn, 0, sizeof(dfn));
                memset(low, 0, sizeof(low));
                memset(iscut, 0, sizeof(iscut));
                dfs(1, -1);
                printf("%d\n", ans);
        }

        return 0;
}
