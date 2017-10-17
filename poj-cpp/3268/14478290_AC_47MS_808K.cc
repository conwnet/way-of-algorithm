#include <stdio.h>
#include <queue>

using namespace std;

struct Edge {
	int to, cost;
};

typedef pair<int, int> P;

vector<Edge> G[2][1024];
int N, M, X, d[2][1024];

void dijkstra(int n, int s)
{
	priority_queue<P, vector<P>, greater<P> > pq;

	for(int i=0; i<=N; i++) d[n][i] = 1<<30;
	d[n][s] = 0;
	pq.push(P(0, s));
	while(!pq.empty()) {
		P tmp = pq.top(); pq.pop();
		if(tmp.first > d[n][tmp.second]) continue;
		for(int i=0; i<G[n][tmp.second].size(); i++) {
			Edge &e = G[n][tmp.second][i];
			if(tmp.first+e.cost < d[n][e.to]) {
				d[n][e.to] = tmp.first + e.cost;
				pq.push(P(d[n][e.to], e.to));
			}
		}
	}
}

int main()
{
	int u, v, c;

	scanf("%d%d%d", &N, &M, &X);
	while(M--) {
		scanf("%d%d%d", &u, &v, &c);
		G[0][u].push_back((Edge){v, c});
		G[1][v].push_back((Edge){u, c});
	}
	dijkstra(0, X);
	dijkstra(1, X);
	int ans = 0;
	for(int i=1; i<=N; i++) {
		if(d[0][i]+d[1][i] > ans)
			ans = d[0][i] + d[1][i];
	}
	printf("%d\n", ans);
}













