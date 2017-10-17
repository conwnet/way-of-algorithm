#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 160000;
int dp[maxn][2];

int main()
{
        int N, n, ans = 0;

        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%d", &n);
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+n);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0]-n);
        }
        printf("%d\n", max(dp[N][0], dp[N][1]));


        return 0;
}
