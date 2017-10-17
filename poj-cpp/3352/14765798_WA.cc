#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1100;

struct Edge {
        int v, next;
}edge[maxn];

int low[maxn], dfn[maxn], fir[maxn], vst[maxn];
int N, M, ec = 0, ebcc = 0;

void add_edge(int u, int v)
{
        edge[ec].v = v;
        edge[ec].next = fir[u];
        fir[u] = ec++;
        edge[ec].v = u;
        edge[ec].next = fir[v];
        fir[v] = ec++;
}

void tarjan(int u, int p)
{

        low[u] = dfn[u] = ++ebcc;
        for(int i=fir[u]; i!=-1; i=edge[i].next) {
                int v = edge[i].v;
                if(v==p || dfn[v]>dfn[u]) continue;
                if(!dfn[v]) {
                        tarjan(v, u);
                        if(low[v]<low[u])
                                low[u] = low[v];
                } else if(dfn[v]<low[u])
                        low[u] = dfn[v];
        }
}

int deg[maxn];

int main()
{
        int u, v;

        memset(fir, -1, sizeof(fir));
        memset(low, 0, sizeof(low));
        memset(vst, 0, sizeof(vst));
        scanf("%d%d", &N, &M);
        while(M--) {
                scanf("%d%d", &u, &v);
                add_edge(u, v);
        }
        tarjan(1, -1);
        memset(deg, 0, sizeof(deg));
        for(int i=1; i<=N; i++) {
                for(int j=fir[i]; j!=-1; j=edge[j].next) {
                        int vv = edge[j].v;
                        if(low[vv]!=low[i]) {
                                deg[low[i]]++;
                                deg[low[vv]]++;
                        }
                }
        }
        for(int i=1; i<=N; i++)
                deg[i] >>= 1;
        int ans = 0;
        for(int i=1; i<=N; i++) {
                if(deg[i]==1) ans++;
        }
        printf("%d\n", (ans+1)>>1);

        return 0;
}
