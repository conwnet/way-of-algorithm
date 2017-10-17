#include <stdio.h>
#include <string.h>

const int maxn = 1024;
int fir[maxn], to[maxn*6], next[maxn*6], ec, N, M;

int add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
}

int dfn[maxn], low[maxn], sta[maxn], ins[maxn], ti, cnt, top;
void dfs(int u)
{
        dfn[u] = low[u] = ti++;
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
                        ins[v] = 0;
                } while(u!=v);
        }
}

int tarjan()
{
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(ins, 0, sizeof(ins));
        top = ti = cnt = 0;
        for(int u=1; u<=N; u++) {
                if(!dfn[u]) dfs(u);
        }
        return cnt;
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
                        add_edge(u, v);
                }
                int ans = tarjan();
                if(ans==1) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}
