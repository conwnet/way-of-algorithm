#include <stdio.h>
#include <string.h>

int N, S, c[11000], y[11000], v[11000];
long long ans;

int main()
{
        int i, j;

        scanf("%d%d", &N, &S);
        for(i=0; i<N; i++) scanf("%d%d", &c[i], &y[i]);
        ans = 0;
        memset(v, 0, sizeof(v));
        for(i=0; i<N; i++) {
                if(v[i]) continue;
                ans += c[i]*y[i];
                for(j=i+1; j<N; j++) {
                        if(c[j]-c[i]>S*(j-i)) {
                                ans += y[j]*(c[i]+S*(j-i));
                                v[j] = 1;
                        }
                }
        }
        printf("%lld\n", ans);

        return 0;
}
