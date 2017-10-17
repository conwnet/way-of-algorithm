#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 150;
vector<int> G[maxn];
int N, E, vst[maxn], match[maxn];

int dfs(int u)
{
        vst[u] = 1;
        for(int i=0; i<G[u].size(); i++) {
                int v = G[u][i], w = match[v];
                if(w<0 || !vst[w] && dfs(w)) {
                        match[u] = v;
                        match[v] = u;
                        return 1;
                }
        }
        return 0;
}

int main()
{
        int u, v, T;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &E);
                for(int i=1; i<=N; i++) G[i].clear();
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        G[u].push_back(v);
                        G[v].push_back(u);
                }
                int ans = 0;
                memset(match, -1, sizeof(match));
                for(int i=1; i<=N; i++) {
                        memset(vst, 0, sizeof(vst));
                        if(dfs(i)) ans++;
                }
                printf("%d\n", N-ans);
        }

        return 0;
}
