#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 100000000;
int maps[13], N, M;
int dp[13][1<<13];

int main()
{
        int r, c;
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                        scanf("%d", &c);
                        if(!c) maps[i] |= 1<<j;
                }
        }
        for(int i=0; i<1<<M; i++) {
                int j;
                for(j=1; j<M; j++) {
                        if((i&1<<j) && (i&1<<j-1)) break;
                        if((i&1<<j) && (maps[0]&1<<j)) break;
                }
                if(j==M) dp[0][i]++;
        }
        for(int i=1; i<N; i++) {
                for(int j=0; j<1<<M; j++) {
                        if(!dp[i-1][j]) continue;
                        for(int k=0; k<1<<M; k++) {
                                int l;
                                for(l=0; l<M; l++) {
                                        if((k&1<<l) && (k&1<<l-1)) break;
                                        if((k&1<<l) && (j&1<<l)) break;
                                        if((k&1<<l) && (maps[i]&1<<l)) break;
                                }
                                if(l==M) dp[i][k] = (dp[i][k] + dp[i-1][j])%MOD;
                        }
                }
        }
        int ans = 0;
        for(int i=0; i<1<<M; i++) {
                ans = (ans + dp[N-1][i]) % MOD;
        }
        printf("%d\n", ans);

        return 0;
}
