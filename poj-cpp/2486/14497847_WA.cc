#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int dp[110][210][2], N, K;
vector<int> G[110];

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
		for(int i=0; i<=N; i++) G[i].clear();
		for(int i=1; i<=N; i++) {
			scanf("%d", &n);
			for(int j=0; j<=K; j++)
				dp[i][j][0] = dp[i][j][1] = n;
		}
		for(int i=1; i<N; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		dfs(1);
		printf("%d\n", max(dp[1][K][0], dp[1][K][1]));
	}

	return 0;
}





