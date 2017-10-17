#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 128;
int N;
int fir[maxn], to[maxn*maxn], next[128*128], ec;

void add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
}

int dfn[maxn], low[maxn], stk[maxn], ins[maxn];
int bel[maxn], top, ti, cnt;
void dfs(int u)
{
        stk[++top] = u;
        dfn[u] = low[u] = ++ti;
        ins[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i];
                if(!dfn[v]) {
                        dfs(v);
                        if(low[v] < low[u]) low[u] = low[v];
                } else if(ins[v] && dfn[v]<low[u]) {
                        low[u] = dfn[v];
                }
        }
        if(dfn[u]==low[u]) {
                int v; cnt++;
                do {
                        v = stk[top--];
                        ins[v] = 0;
                        bel[v] = cnt;
                } while(u!=v);
        }
}

void find_cc()
{
        top = ti = cnt = 0;
        for(int i=1; i<=N; i++) {
                if(!dfn[i]) dfs(i);
        }
}

vector<int> G[maxn];
int ind[maxn], outd[maxn];

int main()
{
        int u;
        ec = 1;
        memset(fir, -1, sizeof(fir));
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                while(scanf("%d", &u) && u)
                        add_edge(i, u);
        }
        find_cc();
        for(int u=1; u<=N; u++) {
                for(int i=fir[u]; i!=-1; i=next[i]) {
                        int v = to[i];
                        if(bel[u]==bel[v]) continue;
                        G[bel[u]].push_back(bel[v]);
                }
        }
        for(int u=1; u<=cnt; u++) {
                outd[u] = G[u].size();
                for(int i=0; i<G[u].size(); i++) {
                        ind[G[u][i]]++;
                }
        }
        int inc = 0, outc = 0;
        for(int i=1; i<=cnt; i++) if(!ind[i]) inc++;
        for(int i=1; i<=cnt; i++) if(!outd[i]) outc++;
        printf("%d\n%d\n", inc, max(inc, outc));

        return 0;
}
