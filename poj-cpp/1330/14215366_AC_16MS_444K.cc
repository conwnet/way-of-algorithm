#include <stdio.h>
#include <string.h>

int p[11000], N, vst[11000];

int main()
{
        int T, i, u, v, t;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(i=1; i<=N; i++) p[i] = i;
                for(i=1; i<N; i++) {
                        scanf("%d%d", &u, &v);
                        p[v] = u;
                }
                scanf("%d%d", &u, &v);
                memset(vst, 0, sizeof(vst));
                for(t=u; ; t=p[t]) {
                        vst[t] = 1;
                        if(p[t]==t) break;
                }
                for(t=v; !vst[t]; t=p[t]);
                printf("%d\n", t);
        }

        return 0;
}


