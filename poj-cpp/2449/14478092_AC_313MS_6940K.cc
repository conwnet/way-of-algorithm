#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int a, int b):
		to(a), cost(b) {};
	Edge() {}
};

typedef pair<int, int> P;

vector<Edge> G[1024];
vector<Edge> G2[1024];
int N, M, d[1024], S, T, K, vst[1024];

struct CMP {
	bool operator () (P A, P B) {
		return A.second + d[A.first] > B.second + d[B.first];
	}
};

void dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P> > pq;

	for(int i=0; i<=N; i++) d[i] = 1<<30;
	d[s] = 0;
	pq.push(P(0, s));
	while(!pq.empty()) {
		P tmp = pq.top(); pq.pop();
		int t = tmp.second;
		if(tmp.first > d[t])
			continue;
		for(int i=0; i<G2[t].size(); i++) {
			if(d[t]+G2[t][i].cost < d[G2[t][i].to]) {
				d[G2[t][i].to] = d[t] + G2[t][i].cost;
				pq.push(P(d[G2[t][i].to], G2[t][i].to));
			}
		}
	}
}

int Astar(int s)
{
	priority_queue<P, vector<P>, CMP> pq;
	
	pq.push(P(s, 0));
	while(!pq.empty()) {
		P tmp = pq.top(); pq.pop();
		int ss = tmp.first;
		if(ss == T) K--;
		if(K==0) return tmp.second;
		for(int i=0; i<G[ss].size(); i++) {
			pq.push(P(G[ss][i].to, tmp.second+G[ss][i].cost));
		}
	}

	return -1;
}

int main()
{
	int u, v, c;

	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d%d", &u, &v, &c);
		G[u].push_back(Edge(v, c));
		G2[v].push_back(Edge(u, c));
	}
	scanf("%d%d%d", &S, &T, &K);
	if(S==T) K++;
	dijkstra(T);
	if(d[S]==1<<30) printf("-1\n");
	else printf("%d\n", Astar(S));

	return 0;
}


