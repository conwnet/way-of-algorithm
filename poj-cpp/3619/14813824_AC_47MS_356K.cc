#include <stdio.h>

int main()
{
        int N, K;
        int s, t, r;

        scanf("%d%d", &N, &K);
        while(K--) {
                int cnt = N;
                scanf("%d%d%d", &s, &t, &r);
                int n = cnt / (s*t);
                int ans = n*(t+r);
                cnt %= s*t;
                if(!cnt) {
                        ans -= r;
                } else {
                        n = cnt / s;
                        ans += n;
                        if(cnt%s) ans++;
                }
                printf("%d\n", ans);
        }

        return 0;
}
