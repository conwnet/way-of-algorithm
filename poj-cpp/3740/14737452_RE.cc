#include <stdio.h>
#include <string.h>

int N, M;
int mat[20][310];
short dp[2^16][301];

int dfs(int s, int n)
{
        if(n==N+1) return 0;
        if(n>0 && s&1) {
                for(int i=0; i<M; i++)
                        dp[s][i] = dp[s>>1][i] + mat[n][i];
        } else if(n>0 && !(s&1)) {
                for(int i=0; i<M; i++)
                        dp[s][i] = dp[s>>1][i];
        }
        for(int i=0; i<M; i++)
                if(dp[s][i]>1) return 0;
        int i;
        for(i=0; i<M; i++)
                if(!dp[s][i]) break;
        if(i==M) return 1;
        if(dfs(s<<1, n+1)) return 1;
        if(dfs((s<<1)+1, n+1)) return 1;
        return 0;
}

int main()
{
        while(~scanf("%d%d", &N, &M)) {
                for(int i=1; i<=N; i++){
                        for(int j=0; j<M; j++) {
                                scanf("%d", &mat[i][j]);
                        }
                }
                memset(dp, 0, sizeof(dp));
                if(dfs(0, 0)) printf("Yes, I found it\n");
                else printf("It is impossible\n");
        }

        return 0;
}

/**<

0000
1000
0100
1100

 */
