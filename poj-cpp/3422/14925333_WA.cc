#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 2600;
typedef pair<int, int> P;
int pre[maxn], val[maxn], dis[maxn], maps[55][55];
int fir[maxn], to[maxn], next[maxn], ec;
void add_edge(int u, int v)
{
        to[ec] = v;
        next[ec] = fir[u];
        fir[u] = ec++;
}
int Dijkstra(int s, int t)
{
        priority_queue<P> pq;
        memset(dis, 0xbf, sizeof(dis));
        dis[s] = val[s]; pq.push(P(val[s], s));
        while(!pq.empty()) {
                P tmp = pq.top(); pq.pop();
                int u = tmp.second;
                if(dis[u]>tmp.first) continue;
                for(int i=fir[u]; i!=-1; i=next[i]) {
                        if(dis[to[i]] < dis[u]+val[to[i]]) {
                                dis[to[i]] = dis[u]+val[to[i]];
                                pre[to[i]] = u;
                                pq.push(P(dis[to[i]], to[i]));
                        }
                }
        }
        for(int u=t; u!=s; u=pre[u])
                val[u] = 0;
        val[s] = 0;
        return dis[t];
}

int main()
{
        int N, K;
        memset(fir, -1, sizeof(fir)); ec = 0;
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        int u = i*N+j;
                        scanf("%d", &val[u]);
                        if(u%N+1 < N) add_edge(u, u+1);
                        if(u+N < N*N) add_edge(u, u+N);
                }
        }
        int ans = 0;
        for(int i=0; i<K; i++)
                ans += Dijkstra(0, N*N-1);
        printf("%d\n", ans);

        return 0;
}



