#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 5050;
int fir[maxn], to[maxn*100], next[maxn*100], ec, V, E;

void add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u];
        fir[u] = ec++;
}

int sta[maxn], dfn[maxn], low[maxn];
int bel[maxn], ins[maxn], ti, top, cnt;
void tarjan(int u)
{
        dfn[u] = low[u] = ++ti;
        sta[++top] = u; ins[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                if(!dfn[to[i]]) {
                        tarjan(to[i]);
                        if(low[to[i]] < low[u])
                                low[u] = low[to[i]];
                } else if(ins[to[i]] && dfn[to[i]]<low[u]) {
                        low[u] = dfn[to[i]];
                }
        }
        if(dfn[u]==low[u]) {
                int v; cnt++;
                do {
                        v = sta[top--];
                        ins[v] = 0;
                        bel[v] = cnt;
                } while(u!=v);
        }
}

void find_cc()
{
        top = 0; cnt = 0; ti = 0;
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(bel, 0, sizeof(bel));
        memset(ins, 0, sizeof(ins));
        for(int u=1; u<=V; u++) {
                if(!dfn[u]) tarjan(u);
        }
}

int outd[maxn];
void new_graph()
{
        memset(outd, 0, sizeof(outd));
        for(int i=1; i<=V; i++) {
                int u = bel[i];
                for(int j=fir[i]; j!=-1; j=next[j]) {
                        int v = bel[to[j]];
                        if(u!=v) outd[u]++;
                }
        }
}

vector<int> A;
void pushv(int v)
{
        for(int i=1; i<=V; i++)
                if(bel[i]==v) A.push_back(i);
}

int main()
{
        int u, v;
        while(scanf("%d", &V) && V) {
                scanf("%d", &E);
                memset(fir, -1, sizeof(fir)); ec = 0;
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        add_edge(u, v);
                }
                find_cc();
                new_graph();
                A.clear();
                for(int i=1; i<=cnt; i++) {
                        if(!outd[i]) pushv(i);
                }
                sort(A.begin(), A.end());
                printf("%d", A[0]);
                for(int i=1; i<A.size(); i++)
                        printf(" %d", A[i]);
                printf("\n");
        }

        return 0;
}
