#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
        int to, cost, next;
};

typedef long long ll;
const int maxn = 50005;
const int INF = 0x3f3f3f3f;
Edge edge[maxn*2];
int fir[maxn];
int V, E, ec=0;
ll wei[maxn];

void add_edge(int u, int v, int w)
{
        edge[ec].to = v; edge[ec].cost = w;
        edge[ec].next = fir[u]; fir[u] = ec++;
        edge[ec].to = u; edge[ec].cost = w;
        edge[ec].next = fir[v]; fir[v] = ec++;
}

ll dis[maxn];
int inq[maxn];

void spfa(int s)
{
        queue<int> que;
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0;
        que.push(s);
        while(!que.empty()) {
                int u = que.front();
                que.pop();
                inq[u] = 0;
                for(int i=fir[u]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(dis[e.to] > dis[u]+e.cost) {
                                dis[e.to] = dis[u]+e.cost;
                                if(inq[e.to]) continue;
                                que.push(e.to);
                        }
                }
        }
}

int main()
{
        int T, u, v, w;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &V, &E);
                for(int i=1; i<=V; i++)
                        scanf("%d", &wei[i]);
                memset(fir, -1, sizeof(fir)); ec = 0;
                while(E--) {
                        scanf("%d%d%d", &u, &v, &w);
                        add_edge(u, v, w);
                }
                spfa(1);
                ll ans = 0;
                for(int i=1; i<=V; i++) {
                        if(dis[i]>=INF) {ans=-1; break;}
                        ans += wei[i]*dis[i];
                }
                if(ans==-1) printf("No Answer\n");
                else printf("%lld\n", ans);
        }

        return 0;
}
