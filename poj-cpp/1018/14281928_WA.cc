#include <stdio.h>
#include <string.h>

struct ADT {
        int b, p;
}prev[128], dev[128];

int min(int a, int b)
{
        return a<b?a:b;
}

int main()
{
        int T, N, i, j, n, pn, b, p, maxf;
        double maxs;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &pn);
                for(i=0; i<pn; i++) scanf("%d%d", &prev[i].b, &prev[i].p);
                while(--N) {
                        scanf("%d", &n);
                        for(i=0; i<n; i++) {
                                scanf("%d%d", &b, &p);
                                for(j=0, maxs=0; j<pn; j++) {
                                        double t = (double)min(prev[j].b, b)/(prev[j].p+p);
                                        if(t>maxs) { maxs = t; maxf = j; }
                                }
                                dev[i] = { min(prev[maxf].b, b), prev[maxf].p+p };
                        }
                        memcpy(prev, dev, n*sizeof(ADT));
                        pn = n;
                }
                for(i=0, maxs=0; i<n; i++) {
                        double t = (double)dev[i].b/dev[i].p;
                        if(t>maxs) { maxs = t; }
                }
                printf("%.3lf\n", maxs);
        }

        return 0;
}

