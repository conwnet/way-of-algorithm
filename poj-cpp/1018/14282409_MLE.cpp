#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 99999999;

struct ADT {
        int b, p;
} dev[128][128];

struct Index {
        int a, b, c;
        bool operator < (const Index& B) const {
                if(a!=B.a) return a<B.a;
                if(b!=B.b) return b<B.b;
                return c<B.c;
        }
        Index(int x, int y, int z) {
                a = x; b = y; c = z;
        }
};

int size[128], N;
map<Index, double> mp;

double dfs(int n, int b, int sp);

int main()
{
        int T, n, i, j;

        scanf("%d", &T);
        while(T--) {
                mp.clear();
                scanf("%d", &N);
                for(i=0; i<N; i++) {
                        scanf("%d", &n);
                        size[i] = n;
                        for(j=0; j<n; j++)
                                scanf("%d%d", &dev[i][j].b, &dev[i][j].p);
                }
                printf("%.3lf\n", dfs(0, INF, 0));
        }

        return 0;
}

double dfs(int n, int b, int sp)
{
        double t = 0;
        if(mp[Index(n, b, sp)]) return mp[Index(n, b, sp)];
        if(n==N) return (double)b/sp;
        for(int i=0; i<size[n]; i++) {
                t = max(t, dfs(n+1, min(b, dev[n][i].b), sp+dev[n][i].p));
        }
        return mp[Index(n, b, sp)] = t;
}



