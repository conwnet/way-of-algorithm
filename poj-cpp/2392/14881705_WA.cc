#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[40010][2], ra[410];
int ele[410][3], K;

int cmp(int a, int b)
{
        return ele[a][1] < ele[b][1];
}

int main()
{
        scanf("%d", &K);
        for(int i=0; i<K; i++)
                scanf("%d%d%d", &ele[i][0], &ele[i][1], &ele[i][2]);
        for(int i=0; i<K; i++) ra[i] = i;
        sort(ra, ra+K, cmp);
        dp[0][0^1] = 1;
        for(int i=0; i<K; i++) {
                int r = ra[i];
                for(int j=0; j<=40000; j++) {
                        if(!dp[j][i^1]) continue;
                        for(int k=0; k<=ele[r][2] && j+k*ele[r][0]<=ele[r][1]; k++) {
                                dp[j+k*ele[r][0]][i] = 1;
                        }
                }
        }
        int ans;
        for(ans=40000; ans>=0; ans--)
                if(dp[ans][K-1^1]) break;
        printf("%d\n", ans);

        return 0;
}
