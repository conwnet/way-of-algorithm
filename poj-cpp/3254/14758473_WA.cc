#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 100000000;
int dp[13][1<<13], maps[13][13], N, M;

int dfs(int r, int c, int s, int n)
{
        if(n==0) return 1;
        if(c>=M) return dfs(r+1, 0, s, n);
        if(r>=N) return 0;
        if(dp[r][s]) return dp[r][s];
        if(s & 1<<c) return dfs(r, c+1, s, n);
        if(maps[r][c]==0) return dfs(r, c+1, s, n);
        return dp[r][s] = dfs(r, c+2, s | 1<<c, n-1)+dfs(r, c+1, s, n);
}

int main()
{
        scanf("%d%d", &N, &M);

        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++)
                        scanf("%d", &maps[i][j]);
        }
        int ans = 0;
        for(int i=1; i<=N*M/2; i++) {
                memset(dp, 0, sizeof(dp));
                ans += dfs(0, 0, 0, i);
                ans %= MOD;
        }

        printf("%d\n", ans+1);

        return 0;
}
