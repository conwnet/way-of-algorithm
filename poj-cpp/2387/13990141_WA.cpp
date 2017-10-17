#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int u[3000], v[3000], w[3000], p[3000],r[3000], T, N;

int findp(int a)
{
        return p[a]==a?a:p[a]=findp(p[a]);
}

int cmp(int a, int b){
        return w[a]<w[b];
}

int kruskal();

int main()
{
        int i, j;

        scanf("%d%d", &T, &N);
        for(i=0; i<T; i++){
                scanf("%d%d%d", &u[i], &v[i], &w[i]);
        }
        printf("%d\n", kruskal());


        return 0;
}

int kruskal()
{
        int rzt = 0, i;
        for(i=0; i<=T; i++){
                p[i] = i;
                r[i] = i;
        }
        sort(r, r+T, cmp);
        for(i=0; i<T; i++){
                int t = r[i];
                int x = findp(u[t]);
                int y = findp(v[t]);

                if(x!=y){
                        rzt += w[t];
                        p[y] = x;
                }
        }
        return rzt;
}
