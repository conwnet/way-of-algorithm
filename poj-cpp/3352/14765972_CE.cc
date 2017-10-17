#include <stdio.h>
#include <string.h>

const int maxn = 1100;
struct Edge {
        int v, next;
}edge[maxn*2];

int low[maxn], dfn[maxn], fir[maxn], vst[maxn];
int N, M, ec, ebcc;

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

        low[u] = ++ebcc;
        for(int i=fir[u]; i!=-1; i=edge[i].next) {
                int v = edge[i].v;
                if(v==p) continue;
                if(!low[v]) {
                        tarjan(v, u);
                if(low[v]<low[u])
                        low[u] = low[v];
        }
}

int deg[maxn];

int main()
{
        int u, v;

        scanf("%d%d", &N, &M);
        memset(fir, -1, sizeof(fir));
        ec = ebcc = 0;
        while(M--) {
                scanf("%d%d", &u, &v);
                add_edge(u, v);
        }
        tarjan(1, -1);
        for(int i=1; i<=N; i++) {
                for(int j=fir[i]; j!=-1; j=edge[j].next) {
                        int vv = edge[j].v;
                        if(low[vv]!=low[i]) {
                                deg[low[i]]++;
                                deg[low[vv]]++;
                        }
                }
        }

        int ans = 0;
        for(int i=1; i<=N; i++) {
                if(deg[i]>>1==1) ans++;
        }
        printf("%d\n", (ans+1)>>1);
        return 0;
}
