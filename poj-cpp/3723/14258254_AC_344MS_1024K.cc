#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Edge {
        int s, t, c;
        bool operator < (const Edge& b) const {
                return c<b.c;
        }
};

Edge edge[51000];
int  p[21000], R, V;

int kruskal();
int findp(int x);

int main()
{
        int T, N, M, i, s, t, c;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d%d", &N, &M, &R);
                V = M+N;
                for(i=0; i<R; i++) {
                        scanf("%d%d%d", &s, &t, &c);
                        edge[i].s = s;
                        edge[i].t = N+t;
                        edge[i].c = -c;
                }
                printf("%d\n", 10000*V+kruskal());
        }

        return 0;
}

int findp(int x)
{
        return x==p[x]?x:p[x]=findp(p[x]);
}

int kruskal()
{
        int i, ans;

        sort(edge, edge+R);
        for(i=0; i<=V; i++) p[i] = i;
        ans = 0;
        for(i=0; i<R; i++) {
                int x = findp(edge[i].s);
                int y = findp(edge[i].t);
                if(x!=y) {
                        p[x] = y;
                        ans += edge[i].c;
                }
        }
        return ans;
}

