#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge { int s, t, c; };

vector<Edge> G;
int arr[110][110], p[110], N;

int kruskal();
int findp(int x)
{
        return x==p[x]?x:p[x]=findp(p[x]);
}
int cmp(Edge a, Edge b)
{
        return a.c<b.c;
}

int main()
{
        int i, j, k, Q;

        scanf("%d", &N);
        for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                        scanf("%d", &arr[i][j]);
        scanf("%d", &Q);
        while(Q--) {
                scanf("%d%d", &i, &j);
                arr[i-1][j-1] = arr[j-1][i-1] = 0;
        }
        for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                        G.push_back(Edge{i, j, arr[i][j]});

        printf("%d\n", kruskal());

        return 0;
}

int kruskal()
{
        int i, ans = 0;
        for(i=0; i<=N; i++) p[i] = i;
        sort(G.begin(), G.end(), cmp);
        for(i=0; i<G.size(); i++) {
                int x = findp(G[i].s);
                int y = findp(G[i].t);
                if(x!=y) {
                        p[x] = y;
                        ans += G[i].c;
                }
        }
        return ans;
}
