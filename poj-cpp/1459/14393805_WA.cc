#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAX_V 1100

using namespace std;

struct Edge {
	int t, c, r;
};

vector<Edge> G[MAX_V];
int used[MAX_V], N, NP, NC, M;
int level[MAX_V], iter[MAX_V];

void add_edge(int s, int t, int c);
int max_flow(int s, int t);
int dfs(int s, int t, int f);
void bfs(int s);

int main()
{
	int u, v, w;

	while(~scanf("%d%d%d%d", &N, &NP, &NC, &M)) {
		while(M--) {
			while(getchar()!='(');
			scanf("%d,%d)%d", &u, &v, &w);
			add_edge(u, v, w);
		}
		while(NP--) {
			while(getchar()!='(');
			scanf("%d)%d", &u, &w);
			add_edge(N, u, w);
		}
		while(NC--) {
			while(getchar()!='(');
			scanf("%d)%d", &u, &w);
			add_edge(u,  N+1, w);
		}
		printf("%d\n", max_flow(N, N+1));
	}

	return 0;
}

void add_edge(int s, int t, int c)
{
	G[s].push_back((Edge){t, c, G[t].size()});
	G[t].push_back((Edge){s, 0, G[s].size()-1});
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int i=0; i<G[v].size(); i++) {
			Edge &e = G[v][i];
			if(e.c > 0 && level[e.t] < 0) {
				level[e.t] = level[v] + 1;
				que.push(e.t);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if(v==t) return f;
	for(int &i=iter[v]; i<G[v].size(); i++) {
		Edge &e = G[v][i];
		if(e.c > 0 && level[v] < level[e.t]) {
			int d = dfs(e.t, t, min(f, e.c));
			if(d > 0) {
				e.c -= d;
				G[e.t][e.r].c += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int res = 0;
	while(1) {
		bfs(s);
		if(level[t] < 0) return res;
		memset(iter, 0, sizeof(iter));
		int f;
		while((f = dfs(s, t, INF)) > 0) {
			res += f;
		}
	}
}

