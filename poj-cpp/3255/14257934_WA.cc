#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

struct Edge { int to, c; };

vector<Edge> G[6000];
int N, R, d1[6000], d2[6000];

void dijkstra(int s);

int main()
{
        int i, j, s, t, c;

        scanf("%d%d", &N, &R);
        for(i=0; i<R; i++) {
                scanf("%d%d%d", &s, &t, &c);
                G[s].push_back(Edge{t, c});
        }
        dijkstra(1);

        return 0;
}

void dijkstra(int s)
{
        int i;
        priority_queue<P, vector<P>, greater<P> > pq;

        for(i=0; i<=N; i++) d1[i] = d2[i] = 999999;
        pq.push(P(s, 0));
        while(!pq.empty()) {
                P t = pq.top(); pq.pop();
                int v = t.first;
                int d = t.second;
                if(d>d2[v]) continue;
                for(i=0; i<G[v].size(); i++) {
                        Edge e = G[v][i];
                        if(d+e.c<d1[e.to]) {
                                d1[e.to] = d+e.c;
                                pq.push(P(e.to, d+e.c));
                        }
                        if(d+e.c<d2[e.to] && d+e.c>d1[e.to]) {
                                d2[e.to] = d+e.c;
                                pq.push(P(e.to, d+e.c));
                        }
                }
        }
        printf("%d\n", d2[N]);

}
