#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int M;
int V;
vector<int> G[600];
int match[600];
bool used[600];

void add_edge(int u, int v)
{
        G[u].push_back(v);
        G[v].push_back(u);
}

bool dfs(int v)
{
        used[v] = true;
        for(int i=0; i<G[v].size(); i++) {
                int u = G[v][i], w = match[u];
                if(w<0 || !used[w] && dfs(w)) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                }
        }
        return false;
}

int bipart_matching()
{
        int res = 0;
        memset(match, -1, sizeof(match));
        for(int v=0; v<V; v++) {
                if(match[v]<0) {
                        memset(used, 0, sizeof(used));
                        if(dfs(v)) {
                                res++;
                        }
                }
        }
        return res;
}

int main()
{
        int i, j, y, x;

        scanf("%d%d", &V, &M);
        for(i=0; i<M; i++) {
                scanf("%d%d", &y, &x);
                add_edge(y, x);
        }
        printf("%d\n", bipart_matching());

        return 0;
}
