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
                if(!(i&i<<1)) dp[0][i]++;
        }
        for(int i=1; i<N; i++) {
                for(int j=0; j<1<<M; j++) {
                        if(!dp[i-1][j]) continue;
                        for(int k=0; k<1<<M; k++) {
                                if(!(k&k<<1) && !(k&maps[i]) && !(k&j))
                                        dp[i][k] = (dp[i][k] + dp[i-1][j])%MOD;
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
