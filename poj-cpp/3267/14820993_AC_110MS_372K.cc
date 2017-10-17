#include <stdio.h>
#include <string.h>

const int INF = 0x3f3f3f3f;
char str[605][30], S[305];
int W, L, dp[305];

int min(int a, int b)
{
        return a<b ? a : b;
}

int main()
{
        scanf("%d%d", &W, &L);
        scanf("%s", S);
        for(int i=0; i<W; i++) {
                scanf("%s", str[i]);
        }
        dp[L] = 0;
        for(int i=L-1; i>=0; i--) {
                int mins = INF;
                for(int j=0; j<W; j++) {
                        if(str[j][0]!=S[i]) continue;
                        int pm = i, ps = 0;
                        while(pm<L) {
                                if(str[j][ps]==S[pm]) ps++;
                                pm++;
                                if(!str[j][ps]) {
                                        if(dp[pm]+pm-i-ps < mins)
                                                mins = dp[pm]+pm-i-ps;
                                        break;
                                }
                        }
                }
                dp[i] = min(mins, dp[i+1]+1);
        }
        printf("%d\n", dp[0]);

        return 0;
}

