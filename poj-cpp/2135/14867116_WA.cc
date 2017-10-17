#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 2100;
const int maxe = 41000;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge {
        int to, cap, cost, next;
} edge[maxe];
int prevv[maxn], preve[maxe], fir[maxn], ec, N, M;

void add_edge(int u, int v, int w, int c)
{
        edge[ec] = (Edge){v, w, c, fir[u]};
        fir[u] = ec++;
        edge[ec] = (Edge){u, 0, -c, fir[v]};
        fir[v] = ec++;
}

int dis[maxn];

ll min_cost_flow(int s, int t, int f)
{
        ll res = 0;
        while(f>0) {
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                int update = 1;
                while(update) {
                        update = 0;
                        for(int v=1; v<=N; v++) {
                                for(int i=fir[v]; i!=-1; i=edge[i].next) {
                                        Edge &e = edge[i];
                                        if(e.cap>0 && dis[v]+e.cost<dis[e.to]) {
                                                dis[e.to] = dis[v]+e.cost;
                                                prevv[e.to] = v;
                                                preve[e.to] = i;
                                                update = 1;
                                        }
                                }
                        }
                }
                if(dis[t]==INF) return -1;
                int d = f;
                for(int v=t; v!=s; v=prevv[v])
                        d = min(d, edge[preve[v]].cost);
                f -= d;
                res += (ll)d*dis[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        Edge &e = edge[preve[v]];
                        e.cap -= d;
                        edge[preve[v]^1].cap += d;
                }
        }
        return res;
}

int main()
{
        int u, v, w;
        memset(fir, -1, sizeof(fir));
        ec = 0;
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++) {
                scanf("%d%d%d", &u, &v, &w);
                add_edge(u, v, 1, w);
        }
        printf("%lld\n", min_cost_flow(1, N, 2));

        return 0;
}










