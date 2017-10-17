#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cow[30010], N, dp[30010][2];

int main()
{
        scanf("%d", &N);
        for(int i=1; i<=N; i++)
                scanf("%d", &cow[i]);
        for(int i=1; i<=N; i++) {
                if(cow[i]==1) {
                        dp[i][0] = dp[i-1][0];
                        dp[i][1] = min(dp[i][0], dp[i-1][1])+1;
                } else {
                        dp[i][0] = dp[i-1][0]+1;
                        dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
                }
        }
        printf("%d\n", min(dp[N][0], dp[N][1]));

        return 0;
}
