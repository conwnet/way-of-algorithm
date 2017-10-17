#include <stdio.h>
#include <string.h>

int dp[100][100][100];

int w(int a, int b, int c)
{
        if(a<=0 || b<=0 || c<=0) return 1;
        if(dp[a][b][c]) return dp[a][b][c];
        if(a>20 || b>20 || c>20) return dp[20][20][20] = w(20, 20, 20);
        if(a<b && b<c) return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main()
{
        int a, b, c;

        memset(dp, 0, sizeof(dp));
        while(scanf("%d%d%d", &a, &b, &c)) {
                if(a==-1 && b==-1 && c==-1) break;
                printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
        }

        return 0;
}
