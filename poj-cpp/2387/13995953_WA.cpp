#include <stdio.h>
#include <string.h>
#include <algorithm>

#define INF 99999999;

using namespace std;

int w[2100][2100], T, N, v[4500], d[4500];

int dijkstra();

int main()
{
        int i, x, y, t;

        scanf("%d%d", &T, &N);
        for(i=0; i<4400000; i++){
                w[0][i] = INF;
        }
        for(i=0; i<T; i++){
                scanf("%d%d%d", &x, &y, &t);
                w[x-1][y-1] = t;
        }

        printf("%d\n", dijkstra());

        return 0;
}

int dijkstra()
{

        memset(v, 0, sizeof(v));
        for(int i=0; i<N; i++) d[i] = INF;
        d[0] = 0;

        for(int i=0; i<N; i++){
                int x, m = INF;
                for(int y=0; y<N; y++){
                        if(!v[y] && d[y]<=m) m = d[x=y];
                }
                v[x] = 1;
                for(int y=0; y<N; y++) d[y] = min(d[y], d[x]+w[x][y]);
        }

        return d[N-1];
}
