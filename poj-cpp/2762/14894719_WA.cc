#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1024;
vector<int> G[maxn];
int N, M;

int dfn[maxn], low[maxn], val[maxn], ts;
int sta[maxn], ins[maxn], bc, top;
void tarjan(int u)
{
        dfn[u] = low[u] = ++ts;
        sta[++top] = u; ins[u] = 1;
        for(int i=0; i<G[u].size(); i++) {
                int v = G[u][i];
                if(!dfn[v]) {
                        tarjan(v);
                        if(low[v]<low[u])
                                low[u] = low[v];
                } else if(ins[v] && dfn[v]<low[u])
                        low[u] = dfn[v];
        }
        if(dfn[u]==low[u]) {
                bc++;
                int v;
                do {
                        v = sta[top--];
                        ins[v] = 0;
                        val[v] = bc;
                } while(v!=u);
        }
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &M);
                while(M--) {
                        scanf("%d%d", &u, &v);
                        G[u].push_back(v);
                }
                bc = ts = 0;
                memset(val, 0, sizeof(val));
                memset(dfn, 0, sizeof(dfn));
                for(int i=1; i<=N; i++) {
                        if(!val[i]) tarjan(i);
                }
                if(bc==1) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}

