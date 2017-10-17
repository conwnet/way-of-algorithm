#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int dp[110][210][2], N, K;
vector<int> G2[110], G[110];

void build(int u, int root)
{
	for(int i=0; i<G2[u].size(); i++) {
		if(G2[u][i]!=root) {
			G[u].push_back(G2[u][i]);
			build(G2[u][i], u);
		}
	}
}

int dfs(int u)
{
	if(0==G[u].size()) return 0;
	for(int i=0; i<G[u].size(); i++) {
		int v = G[u][i];
		dfs(v);
		for(int j = K; j>=1; j--) {
			for(int i=1; i<=j; i++) {
				dp[u][j][1] = max(dp[u][j][1], dp[u][j-i][1] + dp[v][i-2][1]);
				dp[u][j][0] = max(dp[u][j][0], dp[u][j-i][0] + dp[v][i-2][1]);
				dp[u][j][0] = max(dp[u][j][0], dp[u][j-i][1] + dp[v][i-1][0]);
			}
		}
	}

	return 0;
}

int main()
{
	int u, v, n;
	
	while(~scanf("%d%d", &N, &K)) {
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<=110; i++) G2[i].clear();
		for(int i=0; i<=110; i++) G[i].clear();
		for(int i=1; i<=N; i++) {
			scanf("%d", &n);
			for(int j=0; j<=K; j++)
				dp[i][j][0] = dp[i][j][1] = n;
		}
		for(int i=1; i<N; i++) {
			scanf("%d%d", &u, &v);
			G2[u].push_back(v);
			G2[v].push_back(u);
		}
		build(1, 0);
		dfs(1);
		printf("%d\n", max(dp[1][K][0], dp[1][K][1]));
	}

	return 0;
}









