#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define INF 99999999
#define MAX_V 110

using namespace std;

struct Edge {
	int t, c, r;
};

vector<Edge> G[MAX_V];
int used[MAX_V], N, NP, NC, M;

void add_edge(int s, int t, int c);
int max_flow(int s, int t);
int dfs(int s, int t, int f);

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

int max_flow(int s, int t)
{
	int res = 0;

	while(1) {
		memset(used, 0, sizeof(used));
		int d = dfs(s, t, INF);
		if(!d) return res;
		res += d;
	}
}

int dfs(int s, int t, int f)
{
	if(s==t) return f;
	used[s] = 1;
	for(int i=0; i<G[s].size(); i++) {
		Edge &e = G[s][i];
		if(!used[e.t] && e.c>0) {
			int d = dfs(e.t, t, min(f, e.c));
			if(d>0) {
				e.c -= d;
				G[e.t][e.r].c += d;
				return d;
			}
		}
	}
	return 0;
}









