#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int u[80], v[80], w[80], r[80], p[80], N;

int findp(int x)
{
        if(p[x]==x) return x;
        return p[x] = findp(p[x]);
}

int cmp(int a, int b)
{
        return w[a] < w[b];
}

int kruskal()
{
        int i, ans = 0;

        for(i=0; i<=N; i++) {
                p[i] = i;
                r[i] = i;
        }
        sort(r, r+N, cmp);
        for(i=0; i<N; i++) {
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
        int C, n, l;
        char sv[5];

        while(scanf("%d", &C) && C) {
                N = 0;
                while(--C) {
                        scanf("%s%d", sv, &n);
                        int t = sv[0]-'A';
                        while(n--) {
                                scanf("%s%d", sv, &l);
                                u[N] = t;
                                v[N] = sv[0]-'A';
                                w[N++] = l;
                        }
                }
                printf("%d\n", kruskal());
        }

        return 0;
}
