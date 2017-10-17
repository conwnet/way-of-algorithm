#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 1024;
struct Edge {
        int to, cost, next;
} edge[maxn*100];
int fir[maxn], ec;
int dis[maxn], cnt[maxn], N, M;

void add_edge(int u, int v, int w)
{
        edge[ec] = (Edge){v, w, fir[u]};
        fir[u] = ec++;
}

int spfa(int s)
{
        queue<int> que;
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        dis[s] = 0; que.push(s);
        while(!que.empty()) {
                int u = que.front(); que.pop();
                for(int i=fir[u]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(dis[u]+e.cost < dis[e.to]) {
                                dis[e.to] = dis[u]+e.cost;
                                que.push(e.to);
                                cnt[u]++;
                                if(cnt[u]==N) return 0;
                        }
                }
        }
        return 1;
}

int main()
{
        char type[5];
        int u, v, w;
        while(~scanf("%d%d", &N, &M)) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                while(M--) {
                        scanf("%s", type);
                        if('P'==type[0]) {
                                scanf("%d%d%d", type, &u, &v, &w);
                                add_edge(u, v, -w);
                                add_edge(v, u, w);
                        } else {
                                scanf("%d%d", &u, &v);
                                add_edge(u, v, 0);
                        }
                }
                if(spfa(1)) printf("Reliable\n");
                else printf("Unreliable\n");
        }

        return 0;
}
