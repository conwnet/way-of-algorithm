#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char S1[1024], S2[1024];
int dp[1024][1024];

int main()
{
        int N, M;

        scanf("%d%s%d%s", &M, S1+1, &N, S2+1);
        dp[0][0] = 0;
        for(int i=1; i<=M; i++) {
                for(int j=1; j<=N; j++) {
                        if(S1[i]==S2[j]) dp[i][j] = dp[i-1][j-1]+1;
                        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
        }
        printf("%d\n", N-dp[M][N]);

        return 0;
}
