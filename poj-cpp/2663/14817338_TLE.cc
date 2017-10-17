#include <stdio.h>
#include <string.h>

int N, dp[3][31][8];

int dfs(int r, int c, int s)
{
        if(c==N) return 1;
        if(r==3) return dfs(0, c+1, s);
        if(dp[r][c][s]) return dp[r][c][s];
        if(s & 1<<r) return dfs(r+1, c, s-(1<<r));
        int ret = 0;
        if(c+1<N) ret = dfs(r+1, c, s|1<<r);
        if(r+1<3 && !(s&1<<r+1))
                ret += dfs(r+2, c, s);
        return dp[r][c][s] = ret;
}

int main()
{
        while(scanf("%d", &N)) {
                if(N==-1) break;
                memset(dp, 0, sizeof(dp));
                printf("%d\n", dfs(0, 0, 0));
        }

        return 0;
}
