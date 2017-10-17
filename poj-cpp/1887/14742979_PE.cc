#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int mle[40000], dp[40000];

int main()
{
        int nC = 0;
        while(1) {
                int cnt = 0;
                scanf("%d", &mle[cnt++]);
                if(mle[0]==-1) break;
                while(scanf("%d", &mle[cnt])) {
                        if(mle[cnt]==-1) break;
                        else cnt++;
                }
                int ans = 0;
                memset(dp, 0, sizeof(dp));
                for(int i=0; i<cnt; i++) {
                        for(int j=0; j<i; j++) {
                                if(mle[j]>=mle[i]) {
                                        dp[i] = max(dp[i], dp[j]+1);
                                        ans = max(ans, dp[i]);
                                }
                        }
                }
                printf("Test #%d:\n", ++nC);
                printf("  maximum possible interceptions: %d\n", ans+1);

        }

        return 0;
}
