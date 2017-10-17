#include <stdio.h>
#include <string.h>

const int maxn = 11;
typedef long long ll;

int dp[maxn][maxn][1<<maxn];
int N, M;

int dfs(int r, int c, int sta)
{
	if(r==N)
		return 1;
	if(c!=M && dp[r][c][sta]!=-1)
		return dp[r][c][sta];
	if(c==M)
		return dfs(r+1, 0, sta);
	if(sta & 1<<c)
		return dfs(r, c+1, sta ^ 1<<c);
	int res = 0;
	if(c+1<M && !(sta & 1<<(c+1)))
		res += dfs(r, c+2, sta);
	if(r+1<N)
		res += dfs(r, c+1, sta | 1<<c);
	return dp[r][c][sta] = res;
}

int main()
{
	while(scanf("%d%d", &N, &M)) {
		if(!N && !M) break;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", dfs(0, 0, 0));
	}

	return 0;
}
