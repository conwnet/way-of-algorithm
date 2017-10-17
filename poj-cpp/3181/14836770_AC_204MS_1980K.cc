#include <stdio.h>
#include <string.h>

typedef long long ll;
const long long INF = 1000000000000000000;
ll dpa[128][2048], dpb[128][2048];
int N, K;

int main()
{
        scanf("%d%d", &N, &K);
        dpa[0][0] = 1;
        for(int i=1; i<=K; i++) {
                for(int j=0; j<=N; j++) {
                        for(int k=0; k*i<=j; k++) {
                                dpa[i][j] += dpa[i-1][j-i*k];
                                dpb[i][j] += dpb[i-1][j-i*k];
                                dpb[i][j] += dpa[i][j]/INF;
                                dpa[i][j] %= INF;
                        }
                }
        }
        if(dpb[K][N]) printf("%lld", dpb[K][N]);
        printf("%lld\n", dpa[K][N]);

        return 0;
}