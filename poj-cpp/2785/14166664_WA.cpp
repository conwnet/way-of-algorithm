#include <stdio.h>
#include <algorithm>

using namespace std;

int A[4100], B[4100], C[4100], D[4100], sum[4000*4000+1000];

int main()
{
        int i, j, N, cnt, t;
        long long ans;

        scanf("%d", &N);
        for(i=0; i<N; i++) scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        for(i=0, cnt=0; i<N; i++)
                for(j=0; j<N; j++)
                        sum[cnt++] = A[i]+B[j];
        sort(sum, sum+cnt);
        for(i=0, ans=0; i<N; i++) {
                for(j=0; j<N; j++) {
                        t = 0-C[i]-D[j];
                        if(*lower_bound(sum, sum+cnt, t)==t) ans++;
                }
        }
        printf("%lld\n", ans);

        return 0;
}
