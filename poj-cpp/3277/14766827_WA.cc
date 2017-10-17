#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int bud[40010][3];
int hsh[80010], hcnt = 0;
int N, hei[160010], lazy[160010];
int seg[80010];


int main()
{
        int n;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%d%d%d", &bud[i][0], &bud[i][1], &bud[i][2]);
                hsh[++hcnt] = bud[i][0];
                hsh[++hcnt] = bud[i][1];
        }
        sort(hsh+1, hsh+1+hcnt);
        hcnt = unique(hsh+1, hsh+1+hcnt) - hsh-1;
        for(int i=0; i<N; i++) {
                n = lower_bound(hsh+1, hsh+1+hcnt, bud[i][0]) - hsh;
                bud[i][0] = n;
                n = lower_bound(hsh+1, hsh+1+hcnt, bud[i][1]) - hsh;
                bud[i][1] = n;
        }
        for(int i=0; i<N; i++) {
                int l = bud[i][0], r = bud[i][1];
                for(int j=l; j<r; j++) {
                        if(seg[j]<bud[i][2])
                                seg[j] = bud[i][2];
                }
        }
        ll ans = 0;
        for(int i=1; i<hcnt; i++)
                ans += (hsh[i+1]-hsh[i])*seg[i];
        printf("%lld\n", ans);

        return 0;
}
