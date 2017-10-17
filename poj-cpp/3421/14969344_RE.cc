#include <stdio.h>
#define INF 104880

int len[INF], cnt[INF];

void solve()
{
        int i, k, c = INF/2;
        len[1] = 0; cnt[1] = 1;
        for(i=1; i<c; i++) {
                for(k=i*2; k<INF; k+=i) {
                        int t = len[i] + 1;
                        if(t > len[k]) {
                                len[k] = t;
                                cnt[k] = cnt[i];
                        } else if(t==len[k])
                                cnt[k] += cnt[i];
                }
        }
}

int main()
{
        int n;
        solve();
        while(~scanf("%d", &n)) {
                if(n<0) continue;
                printf("%d %d\n", len[n], cnt[n]);
        }

        return 0;
}
