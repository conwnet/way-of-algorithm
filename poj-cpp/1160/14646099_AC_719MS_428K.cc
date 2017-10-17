#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

int dp[305][35];
int V, P, arr[305];

int dfs(int n, int p)
{
        if(dp[n][p]!=-1)
                return dp[n][p];
        if(p==1) {
                int m = (n+V)>>1;
                int tmp = 0;
                for(int j=n; j<V; j++)
                        tmp += abs(arr[j]-arr[m]);
                return tmp;
        }
        int ans = INF;
        for(int i=1; i<=(V-p+1); i++) {
                int m = (n+i)>>1;
                int tmp = 0;
                for(int j=n; j<i; j++)
                        tmp += abs(arr[j]-arr[m]);
                ans = min(ans, tmp + dfs(i, p-1));
        }
        return dp[n][p] = ans;
}


int main()
{
        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &V, &P);
        for(int i=0; i<V; i++)
                scanf("%d", &arr[i]);
        printf("%d\n", dfs(0, P));

        return 0;
}
