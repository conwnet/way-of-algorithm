#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> P;

struct Edge {
        int to, cost;
        Edge(int a, int b):
                to(a), cost(b) {}
        Edge() {}
};

vector<Edge> G1[maxn], G2[maxn];
int d1[maxn], d2[maxn];
int N, M;


void dijkstra(vector<Edge> *G, int *dis)
{
        priority_queue<P> pq;
        fill(dis, dis+N+1, INF);
        //memset(dis, -1, sizeof(dis));
        dis[1] = 0;
        pq.push(P(0, 1));
        while(!pq.empty()) {
                P tmp = pq.top();
                pq.pop();
                int v = tmp.second;
                if(dis[v] < tmp.first)
                        continue;
                for(int i=0; i<G[v].size(); i++) {
                        Edge &e = G[v][i];
                        if(dis[v]+e.cost < dis[e.to]) {
                                dis[e.to] = dis[v]+e.cost;
                                pq.push(P(dis[e.to], e.to));
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
                for(int i=0; i<=N; i++) {
                        G1[i].clear();
                        G2[i].clear();
                }
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &u, &v, &w);
                        G1[u].push_back(Edge(v, w));
                        G2[v].push_back(Edge(u, w));
                }
                dijkstra(G1, d1);
                dijkstra(G2, d2);
                int ans = 0;
                for(int i=1; i<=N; i++)
                        ans += d1[i]+d2[i];
                printf("%d\n", ans);
        }

        return 0;
}
