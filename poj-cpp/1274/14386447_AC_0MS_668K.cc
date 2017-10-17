#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAX_V 500
 
using namespace std;

struct Edge {
	int to, cap, rev;
};

vector<Edge> G[MAX_V];
int used[MAX_V], M, N;

void add_edge(int s, int t, int c)
{
	G[s].push_back((Edge){t, c, G[t].size()});
	G[t].push_back((Edge){s, 0, G[s].size()-1});
}

int dfs(int v, int t, int f)
{
	if(v==t) return f;
	used[v] = 1;
	for(int i=0; i<G[v].size(); i++) {
		Edge& e = G[v][i];
		if(!used[e.to] && e.cap>0) {
			int d = dfs(e.to, t, min(e.cap, f));
			if(d>0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int d, ans = 0;
	
	while(1) {
		memset(used, 0, sizeof(used));
		d = dfs(s, t, INF);
		if(!d) break;
		ans += d;
	}
	return ans;
}

 
int main()
{
        int i, t, n;
 
        while(~scanf("%d%d", &N, &M)) {
                for(i=0; i<=M+N+1; i++) G[i].clear();
                for(i=1; i<=N; i++) add_edge(0, i, 1);
                for(i=1; i<=N; i++) add_edge(N+i, N+M+1, 1);
                for(i=1; i<=N; i++) {
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d", &t);
                                add_edge(i, N+t, 1);
                        }
                }
                printf("%d\n", max_flow(0, N+M+1));
        }
 
        return 0;
}