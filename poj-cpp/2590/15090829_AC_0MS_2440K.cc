#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1<<18;
long long dp[maxn];

int solve()
{
        for(int i=0; i<maxn; i++)
                dp[i] = (long long)i * (i+1);
}

int main()
{
        int T, a, b;

        solve();
//for(int i=0; i<maxn; i++)
  //              if(dp[i]>(1<<31))printf("%d %d ", i, dp[i]);
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &a, &b);
                int c = b - a;
                if(c==0) { printf("0\n"); continue; }
                int t = lower_bound(dp, dp+maxn, c) - dp;
                printf("%d\n", c>dp[t]+dp[t-1]>>1 ? t*2 : t*2-1);
        }

        return 0;
}











