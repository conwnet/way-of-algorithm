#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 100000000;
int dp[13][13][1<<13][80], maps[13][13], N, M;

int dfs(int r, int c, int s, int n)
{
        if(n==0) return 1;
        if(c>=M) return dfs(r+1, 0, s, n)%MOD;
        if(r>=N) return 0;
        if(maps[r][c]==0) return dfs(r, c+1, (s|1<<c)-(1<<c), n)%MOD;
        if(dp[r][c][s][n]!=-1) return dp[r][c][s][n];
        if(s & 1<<c) return dfs(r, c+1, (s|1<<c)-(1<<c), n)%MOD;
        return dp[r][c][s][n] = (dfs(r, c+2, s | 1<<c, n-1)+dfs(r, c+1, (s|1<<c)-(1<<c), n))%MOD;
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++)
                        scanf("%d", &maps[i][j]);
        }
        int ans = 0;

        for(int i=0; i<=N*M/2+1; i++) {
                memset(dp, -1, sizeof(dp));
                ans += dfs(0, 0, 0, i);
                ans %= MOD;
        }
        printf("%d\n", ans);

        return 0;
}
