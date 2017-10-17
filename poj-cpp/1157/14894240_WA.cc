#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 220;
const int INF = 0x3f3f3f3f;
struct Edge {
        int to, cap, cost, next;
}edge[maxn*maxn];
int dis[maxn], prevv[maxn*maxn], preve[maxn*maxn], fir[maxn], V, ec;

void add_edge(int from, int to, int cap, int cost)
{
        edge[ec] = (Edge){to, cap, cost, fir[from]};
        fir[from] = ec++;
        edge[ec] = (Edge){from, 0, -cost, fir[to]};
        fir[to] = ec++;
}

int min_cost_flow(int s, int t, int f)
{
        int res = 0;
        while(f>0) {
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                int update = 1;
                while(update) {
                        update = 0;
                        for(int v=0; v<V; v++) {
                                if(dis[v]==INF) continue;
                                for(int i=fir[v]; i!=-1; i=edge[i].next) {
                                        Edge &e = edge[i];
                                        if(e.cap>0 && dis[e.to]>dis[v]+e.cost) {
                                                dis[e.to] = dis[v]+e.cost;
                                                preve[e.to] = i;
                                                prevv[e.to] = v;
                                                update = 1;
                                        }
                                }
                        }
                }
                if(dis[t]==INF) return -1;
                int d = f;
                for(int v=t; v!=s; v=prevv[v])
                        d = min(d, edge[preve[v]].cap);
                f -= d;
                res += d*dis[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        int e = preve[v];
                        edge[e].cap -= d;
                        edge[e^1].cap += d;
                }
        }
        return res;
}

int F, N;

int main()
{
        int a;
        memset(fir, -1, sizeof(fir)); ec = 0;
        scanf("%d%d", &F, &N);
        for(int i=1; i<=F; i++) {
                for(int j=1; j<=N; j++) {
                        scanf("%d", &a);
                        add_edge(i, F+j, 1, -a);
                }
        }
        for(int i=1; i<=F; i++)
                add_edge(0, i, 1, 0);
        for(int j=1; j<=N; j++)
                add_edge(F+j, F+N+1, 1, 0);
        V = F+N+2;
        printf("%d\n", -min_cost_flow(0, F+N+1, F));

        return 0;
}
