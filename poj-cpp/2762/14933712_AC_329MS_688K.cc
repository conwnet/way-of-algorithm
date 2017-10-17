#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1024;
int fir[maxn], to[maxn*6], next[maxn*6], ec, N, M;

int add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
}

int dfn[maxn], low[maxn], sta[maxn], ins[maxn], bel[maxn], ti, cnt, top;
void dfs(int u)
{
        dfn[u] = low[u] = ++ti;
        sta[++top] = u; ins[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i];
                if(!dfn[v]) {
                        dfs(v);
                        if(low[v]<low[u]) low[u] = low[v];
                } else if(ins[v] && dfn[v]<low[u]) {
                        low[u] = dfn[v];
                }
        }
        if(dfn[u]==low[u]) {
                int v; cnt++;
                do {
                        v = sta[top--];
                        bel[v] = cnt;
                        ins[v] = 0;
                } while(u!=v);
        }
}

int tarjan()
{
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(ins, 0, sizeof(ins));
        memset(bel, 0, sizeof(bel));
        top = ti = cnt = 0;
        for(int u=1; u<=N; u++) {
                if(!dfn[u]) dfs(u);
        }
        return cnt;
}

int ind[maxn], vst[maxn];
vector<int> G[maxn];

int top_sort(int u)
{
        queue<int> que;
        int cc = 0;
        que.push(u);
        while(!que.empty()) {
                int v = que.front(); que.pop();
                vst[v] = 1; cc++;
                for(int i=0; i<G[v].size(); i++) {
                        int w = G[v][i];
                        if(vst[w]) continue;
                        ind[w]--;
                        if(!ind[w]) que.push(w);
                }
                if(que.size()>1) return 0;
        }
        return cc==cnt;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                scanf("%d%d", &N, &M);
                while(M--) {
                        scanf("%d%d", &u, &v);
                        if(u==v) continue;
                        add_edge(u, v);
                }
                tarjan();
                for(int i=1; i<=cnt; i++) G[i].clear();
                memset(ind, 0, sizeof(ind));
                for(int u=1; u<=N; u++) {
                        for(int i=fir[u]; i!=-1; i=next[i]) {
                                if(bel[u]==bel[to[i]]) continue;
                                G[bel[u]].push_back(bel[to[i]]);
                                ind[bel[to[i]]]++;
                        }
                }
                int cnt0 = 0, f;
                for(int u=1; u<=cnt; u++)
                        if(ind[u]==0) { cnt0++; f = u; }
                memset(vst, 0, sizeof(vst));
                if(cnt0>1 || !top_sort(f)) printf("No\n");
                else printf("Yes\n");
        }

        return 0;
}
