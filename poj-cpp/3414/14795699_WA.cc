#include <stdio.h>
#include <string.h>

int A, B, C, path[20], H;
const int maxh = 20;
int dp[100][128][128];

int dfs(int h, int a, int b)
{
        int z;
        if(a==C || b==C) return dp[h][a][b] = 1;
        if(h==H) return 0;
        if(dp[h][a][b]!=-1) return dp[h][a][b];
        path[h] = 1;
        if(dfs(h+1, A, b)) return 1;
        path[h] = 2;
        if(dfs(h+1, a, B)) return 1;
        path[h] = 3;
        if(dfs(h+1, 0, b)) return 1;
        path[h] = 4;
        if(dfs(h+1, a, 0)) return 1;
        path[h] = 5;
        if(dfs(h+1, a>B-b?a+b-B:0, a>B-b?B:b+a)) return 1;
        path[h] = 6;
        if(dfs(h+1, b>A-a?A:a+b, b>A-a?b+a-A:0)) return 1;
        return dp[h][a][b] = 0;
}

int main()
{
        scanf("%d%d%d", &A, &B, &C);
        for(H=1; H<maxh; H++) {
                memset(dp, -1, sizeof(dp));
                if(dfs(0, 0, 0)) break;
        }
        if(H==maxh) printf("impossible\n");
        else {
                printf("%d\n", H);
                for(int i=0; i<H; i++) {
                        if(path[i]==1) printf("FILL(1)\n");
                        else if(path[i]==2) printf("FILL(2)\n");
                        else if(path[i]==3) printf("DROP(1)\n");
                        else if(path[i]==4) printf("DROP(2)\n");
                        else if(path[i]==5) printf("POUR(1,2)\n");
                        else if(path[i]==6) printf("POUR(2,1)\n");
                }
        }

        return 0;
}






