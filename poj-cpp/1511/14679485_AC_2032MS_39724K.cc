#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;

struct Edge {
        int to, cost, next;
        Edge(int a, int b):
                to(a), cost(b) {}
        Edge() {}
};

Edge G[2][maxn];
int fir[2][maxn], dis[2][maxn];
int N, M;


void dijkstra(int n)
{
        priority_queue<P> pq;
        memset(dis[n], 0x3f, sizeof(dis[n]));
        dis[n][1] = 0;
        pq.push(P(0, 1));
        while(!pq.empty()) {
                P tmp = pq.top();
                pq.pop();
                int v = tmp.second;
                if(dis[n][v] < tmp.first)
                        continue;
                for(int i=fir[n][v]; i!=-1; i=G[n][i].next) {
                        Edge &e = G[n][i];
                        if(dis[n][v]+e.cost < dis[n][e.to]) {
                                dis[n][e.to] = dis[n][v]+e.cost;
                                pq.push(P(dis[n][e.to], e.to));
                        }
                }
        }
}

int main()
{
        int T, u, v, w;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &M);
                memset(fir, -1, sizeof(fir));
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &u, &v, &w);
                        G[0][i] = Edge(v, w);
                        G[0][i].next = fir[0][u];
                        fir[0][u] = i;
                        G[1][i] = Edge(u, w);
                        G[1][i].next = fir[1][v];
                        fir[1][v] = i;
                }
                dijkstra(0);
                dijkstra(1);
                ll ans = 0;
                for(int i=1; i<=N; i++)
                        ans += dis[0][i]+dis[1][i];
                printf("%lld\n", ans);
        }

        return 0;
}
