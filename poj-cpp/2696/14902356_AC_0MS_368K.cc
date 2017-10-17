#include <stdio.h>
#include <string.h>

int dp[1024], a, b, c, d, e, f, g, h, i;

int dfs(int i)
{
        if(i==0) return a;
        if(i==1) return b;
        if(i==2) return c;
        if(dp[i]>=0) return dp[i];
        if(i&1) return dp[i] = ((d*dfs(i-1) + e*dfs(i-2) - f*dfs(i-3))%g + g)%g;
        else return dp[i] = ((f*dfs(i-1) - d*dfs(i-2) + e*dfs(i-3))%h + h)%h;
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                memset(dp, -1, sizeof(dp));
                scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
                printf("%d\n", dfs(i));
        }

        return 0;
}
