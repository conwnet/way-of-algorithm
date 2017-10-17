#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 128;
struct Edge {
        int from, to, cost, next;
}edge[maxn];
int N, M, fir[maxn], ec, vst[maxn];

void add_edge(int u, int v, int w)
{
        edge[ec].from = u; edge[ec].to = v; edge[ec].cost = w;
        edge[ec].next = fir[u]; fir[u] = ec++;
}

int is_ok(int w)
{
        queue<int> que;
        for(int i=0; i<M; i++) {
                memset(vst, 0, sizeof(vst));
                int maxs = edge[i].cost;
                int mins = edge[i].cost;
                vst[edge[i].from] = vst[edge[i].to] = 1;
                while(!que.empty()) que.pop();
                que.push(edge[i].from); que.push(edge[i].to);
                while(!que.empty()) {
                        int v = que.front(); que.pop();
                        for(int i=fir[v]; i!=-1; i=edge[i].next) {
                                Edge &e = edge[i];
                                if(vst[e.to]) continue;
                                if(abs(e.cost-maxs)>w || abs(e.cost-mins)>w)
                                        continue;
                                if(e.cost>maxs) maxs = e.cost;
                                if(e.cost<mins) mins = e.cost;
                                vst[e.to] = 1;
                                que.push(e.to);
                        }
                }
                int cnt = 0;
                for(int i=1; i<=N; i++) if(vst[i]) cnt++;
                if(cnt==N) return 1;
        }
        return 0;
}

int main()
{
        int u, v, w;
        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                ec = 0;
                memset(fir, -1, sizeof(fir));
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &u, &v, &w);
                        add_edge(u, v, w);
                        add_edge(v, u, w);
                }
                int l = 0, r = 10010;
                while(l<r) {
                        int m = (l+r)>>1;
                        if(is_ok(m)) r = m;
                        else l = m+1;
                }
                printf("%d\n", l<10010 ? l : -1);
        }

        return 0;
}
