#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int N, w[1024], u[1024], v[1024], r[1024], p[1024], cnt, maxs, kru;

void kruskal();
int cmp(int a, int b)
{
        return w[a]<w[b];
}
int findp(int a)
{
        return a==p[a] ? a : p[a] = findp(p[a]);
}

int main()
{      
        int nCase, i, j;

        scanf("%d", &nCase);
        while(nCase--) {
                scanf("%d", &N);
                cnt = 0;
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                u[cnt] = i;
                                v[cnt] = j;
                                scanf("%d", &w[cnt++]);
                        }
                }
                kruskal();
                printf("%d\n", maxs);
                
        }

        return 0;
}

void kruskal()
{      
        int i;

        maxs = kru = 0;
        for(i=0; i<cnt; i++) r[i] = i;
        for(i=0; i<cnt; i++) p[i] = i;
        sort(r, r+cnt, cmp);
        for(i=0; i<cnt; i++) {
                int t = r[i];
                int x = findp(u[t]);
                int y = findp(v[t]);

                if(x!=y) {
                        p[x] = y;
                        kru += w[t];
                        maxs = max(maxs, w[t]);
                }
        }

}


