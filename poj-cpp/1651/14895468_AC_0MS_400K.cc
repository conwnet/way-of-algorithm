#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[110][110], dat[110], N;

int main()
{
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
                scanf("%d", &dat[i]);
        memset(dp, 0x3f, sizeof(dp));
        for(int i=1; i<N; i++)
                dp[i][i] = dp[i][i+1] = 0;
        for(int i=1; i<N-1; i++)
                dp[i][i+2] = dat[i]*dat[i+1]*dat[i+2];
        for(int i=N-1; i>0; i--) {
                for(int j=i+1; j<=N; j++) {
                        for(int k=i+1; k<j; k++) {
                                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]
                                               +dat[i]*dat[j]*dat[k]);
                        }
                }
        }
        printf("%d\n", dp[1][N]);

        return 0;
}
