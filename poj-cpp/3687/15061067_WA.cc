#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 210;
int G[maxn][maxn], cnt, vst[maxn], V, E, pa[maxn];

int findp(int x)
{
        return pa[x]==x ? x : pa[x] = findp(pa[x]);
}

void dfs(int u)
{
        for(int i=1; i<=V; i++)
                if(G[u][i]) dfs(i);
        if(!vst[u]) vst[u] = cnt++;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &V, &E);
                cnt = 1;
                int faild = 0;
                memset(vst, 0, sizeof(vst));
                memset(G, 0, sizeof(G));
                for(int i=1; i<=V; i++) pa[i] = i;
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        G[v][u] = 1;
                        int x = findp(u);
                        int y = findp(v);
                        if(x!=y) {
                                pa[x] = y;
                        } else faild = 1;
                }
                if(faild) { printf("-1\n"); continue; }
                for(int i=1; i<=V; i++)
                        if(!vst[i]) dfs(i);
                printf("%d", vst[1]);
                for(int i=2; i<=V; i++)
                        printf(" %d", vst[i]);
                printf("\n");
        }

        return 0;
}
