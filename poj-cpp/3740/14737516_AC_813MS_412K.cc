#include <stdio.h>
#include <string.h>

int N, M;
int mat[20][310];
int dp[310];

int dfs(int n)
{
        for(int i=0; i<M; i++)
                if(dp[i]>1) return 0;
        int k;
        for(k=0; k<M && dp[k]; k++);
        if(k==M) return 1;
        if(n>N) return 0;
        if(dfs(n+1)) return 1;
        for(int i=0; i<M; i++)
                dp[i] += mat[n][i];
        if(dfs(n+1)) return 1;
        for(int i=0; i<M; i++)
                dp[i] -= mat[n][i];
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
                if(dfs(1)) printf("Yes, I found it\n");
                else printf("It is impossible\n");
        }

        return 0;
}
