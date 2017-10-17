#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 5120;
const int maxe = 410000;
typedef int ll;
const ll INF = 0x3f3f3f3f;
struct Edge {
        int from, to, cap, cost;
}edge[maxe];
ll dis[maxn];
int pre[maxn], ec;
void add_edge(int from, int to, int cap, int cost)
{
        edge[ec++] = (Edge){from, to, cap, cost};
        edge[ec++] = (Edge){to, from, 0, -cost};
}

ll min_cost_flow(int s, int t, int f)
{
        int res = 0;
        while(f>0) {
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                int update = 1;
                while(update) {
                        update = 0;
                        for(int i=0; i<ec; i++) {
                                Edge &e = edge[i];
                                if(0==e.cap || dis[e.from]==INF) continue;
                                if(dis[e.from]+e.cost<dis[e.to]) {
                                        dis[e.to] = dis[e.from]+e.cost;
                                        pre[e.to] = i;
                                        update = 1;
                                }
                        }
                }
                if(dis[t]==INF) return -1;
                int d = f;
                for(int v=t; v!=s; ) {
                        int i = pre[v];
                        d = min(d, edge[i].cap);
                        v = edge[i].from;
                }
                f -= d;
                res += d*dis[t];
                for(int v=t; v!=s; ) {
                        int i = pre[v];
                        edge[i].cap -= d;
                        edge[i^1].cap += d;
                        v = edge[i].from;
                }
        }
        return res;
}

int main()
{
        int N, K, w;
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        scanf("%d", &w);
                        int u = (i*N+j)*2;
                        add_edge(u, u+1, 1, -w);
                        add_edge(u, u+1, INF, 0);
                        if((u%(N*2))+2<N*2) add_edge(u+1, u+2, INF, 0);
                        if(u+N*2<N*N*2) add_edge(u+1, u+N*2, INF, 0);
                }
        }
        printf("%d\n", -min_cost_flow(0, N*N*2-1, 2));

        return 0;
}
