#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxe = 4000005;
const int maxv = 2005;

int r[maxe], N, E;
short u[maxe], v[maxe], p[maxv];
char w[maxe], str[maxv][10];

int findp(int x)
{
        return p[x]==x ? x : p[x]=findp(p[x]);
}

int cmp_e(int a, int b)
{
        return w[a] < w[b];
}

int kruskal()
{
        for(int i=0; i<E; i++) r[i] = i;
        for(int i=0; i<N; i++) p[i] = i;
        sort(r, r+E, cmp_e);
        int ans = 0;
        for(int i=0; i<E; i++) {
                int t = r[i];
                int x = findp(u[t]);
                int y = findp(v[t]);

                if(x!=y) {
                        p[x] = y;
                        ans += w[t];
                }
        }
        return ans;
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++) {
                        scanf("%s", str[i]);
                }
                E = 0;
                for(int i=1; i<N; i++) {
                        for(int j=0; j<i; j++) {
                                int tmp = 0;
                                for(int k=0; k<7; k++) {
                                        if(str[i][k]!=str[j][k])
                                                tmp ++;
                                }
                                u[E] = i; v[E] = j; w[E++] = tmp;
                                u[E] = j; v[E] = i; w[E++] = tmp;
                        }
                }
                printf("The highest possible quality is 1/%d.\n", kruskal());
        }

        return 0;
}
