#include <stdio.h>
#include <string.h>

const int maxn = 1024;
int fir[maxn], to[maxn*6], next[maxn*6], ec, N, M;
int vst[maxn];
int add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
}

int dfs(int u)
{
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i];
                if(vst[v]) return 1;
                if(dfs(v)) vst[u] = 1;
        }
        return vst[u];
}

void dfs0(int u)
{
        vst[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                if(vst[to[i]]) return ;
                dfs0(to[i]);
        }
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                memset(vst, 0, sizeof(vst));
                scanf("%d%d", &N, &M);
                while(M--) {
                        scanf("%d%d", &u, &v);
                        add_edge(u, v);
                }
                dfs0(1);
                for(int i=1; i<=N; i++) {
                        if(!vst[i]) dfs(i);
                }
                int i;
                for(i=1; i<=N; i++)
                        if(!vst[i]) break;
                if(i<=N) printf("No\n");
                else printf("Yes\n");
        }

        return 0;
}
