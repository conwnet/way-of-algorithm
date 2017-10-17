#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 2048;
const int INF = 0x3f3f3f3f;
int hei[maxn], arr[maxn], N, dp[maxn][maxn];

int main()
{
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%d", &arr[i]);
                hei[i-1] = arr[i];
        }
        sort(hei, hei+N);
        int n = unique(hei, hei+N) - hei;
        int ans = INF;
        memset(dp, 0, sizeof(dp));
        for(int i=N; i>0; i--) {
                for(int j=0; j<n; j++) {
                        int mi = dp[i+1][j];
                        for(int k=j+1; k<n; k++)
                                mi = min(mi, dp[i+1][k]);
                        dp[i][j] = mi + abs(arr[i]-hei[j]);
                }
        }
        for(int i=0; i<n; i++) ans = min(ans, dp[1][i]);
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=N; i++) {
                for(int j=0; j<n; j++) {
                        int mi = dp[i-1][j];
                        for(int k=j+1; k<=0; k++)
                                mi = min(mi, dp[i-1][k]);
                        dp[i][j] = mi + abs(hei[j]-arr[i]);
                }
        }
        for(int i=0; i<n; i++) ans = min(ans, dp[N][i]);
        printf("%d\n", ans);

        return 0;
}


