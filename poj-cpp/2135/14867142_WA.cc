#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
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

ll dis[maxn];

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
}*/

#define INF 0x3f3f3f3f

struct Edge {
        int to, cap, cost, rev;
        Edge(int a, int b, int c, int d):
                to(a), cap(b), cost(c), rev(d) {}
        Edge() {}
};

typedef pair<int, int> Pos;
const int maxv = 2100;

int V, M;
vector<Edge> G[maxv];
int h[maxv], dis[maxv];
int prevv[maxv], preve[maxv];

void add_edge(int from, int to, int cap, int cost)
{
        G[from].push_back(Edge(to, cap, cost, G[to].size()));
        G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
        int res = 0;
        while(f > 0) {
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                bool update = true;
                while(update) {
                        update = false;
                        for(int v = 1; v<=V; v++) {
                                if(dis[v]==INF) continue;
                                for(int i=0; i<G[v].size(); i++) {
                                        Edge &e = G[v][i];
                                        if(e.cap>0 && dis[e.to]>dis[v]+e.cost) {
                                                dis[e.to] = dis[v]+e.cost;
                                                prevv[e.to] = v;
                                                preve[e.to] = i;
                                                update = true;
                                        }
                                }
                        }
                }
                if(dis[t]==INF)
                        return -1;
                int d = f;
                for(int v=t; v!=s; v=prevv[v])
                        d = min(d, G[prevv[v]][preve[v]].cap);
                f -= d;
                res += d*dis[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        Edge &e = G[prevv[v]][preve[v]];
                        e.cap -= d;
                        G[v][e.rev].cap += d;
                }
        }
        return res;
}

int main()
{
        int u, v, w;
      //  memset(fir, -1, sizeof(fir));
       // ec = 0;
        scanf("%d%d", &V, &M);
        for(int i=0; i<M; i++) {
                scanf("%d%d%d", &u, &v, &w);
                add_edge(u, v, 1, w);
        }
        printf("%d\n", min_cost_flow(1, V, 2));

        return 0;
}










