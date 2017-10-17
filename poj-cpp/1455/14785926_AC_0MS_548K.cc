#include <stdio.h>

int dp[50000];

int main()
{
        dp[1] = dp[2] = 0; dp[3] = 1;
        for(int i=4; i<50000; i++) dp[i] = i-2 + dp[i-2];
        int T;
        scanf("%d", &T);
        while(T--) {
                int n;
                scanf("%d", &n);
                printf("%d\n", dp[n]);
        }

        return 0;
}
