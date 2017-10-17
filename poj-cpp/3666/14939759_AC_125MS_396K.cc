#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 2048;
const int INF = 0x3f3f3f3f;
int hei[maxn], arr[maxn], N, dp[2][maxn], mind[maxn];

int main()
{
        int p;
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%d", &arr[i]);
                hei[i-1] = arr[i];
        }
        sort(hei, hei+N);
        int n = unique(hei, hei+N) - hei;
        int ans = INF;
        memset(dp, 0, sizeof(dp));
        memset(mind, 0, sizeof(mind));
        for(int i=N; i>0; i--) {
                if(i&1) p = 1; else p = 0;
                for(int j=0; j<n; j++) {
                        dp[p][j] = mind[j] + abs(arr[i]-hei[j]);
                }
                mind[n-1] = dp[p][n-1];
                for(int j=n-2; j>=0; j--)
                        mind[j] = min(mind[j+1], dp[p][j]);
        }
        for(int i=0; i<n; i++) ans = min(ans, dp[1][i]);
        memset(dp, 0, sizeof(dp));
        memset(mind, 0, sizeof(mind));
        for(int i=1; i<=N; i++) {
                if(i&1) p = 1; else p = 0;
                for(int j=0; j<n; j++) {
                        dp[p][j] = mind[j] + abs(arr[i]-hei[j]);
                }
                mind[n-1] = dp[p][n-1];
                for(int j=n-2; j>=0; j--)
                        mind[j] = min(mind[j+1], dp[p][j]);
        }
        if(N&1) p = 1; else p = 0;
        for(int i=0; i<n; i++) ans = min(ans, dp[p][i]);
        printf("%d\n", ans);

        return 0;
}
