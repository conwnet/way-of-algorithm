#include <stdio.h>
#include <string.h>
#include <math.h>

const int INF = 0x3f3f3f3f;
double maps[128][128];
int N, M, crd[128][2];

double dist(int u, int v)
{
        double x = crd[u][0]-crd[v][0];
        double y = crd[u][1]-crd[v][1];
        return sqrt(x*x+y*y);
}

double dis[128];
int vst[128];
double prim(int s)
{
        double ret = 0;
        for(int i=1; i<=N; i++) dis[i] = INF;
        memset(vst, 0, sizeof(vst));
        int mif = s; vst[s] = 1;
        for(int i=1; i<N; i++) {
                for(int j=1; j<=N; j++) {
                        if(maps[mif][j] < dis[j]+1)
                                dis[j] = maps[mif][j];
                }
                double mi = INF;
                for(int j=1; j<=N; j++) {
                        if(!vst[j] && mi>dis[j]) {
                                mi = dis[j];
                                mif = j;
                        }
                }
                if(mi > INF-1) return -1;
                ret += mi;
                vst[mif] = 1;
        }
        return ret;
}

int main()
{
        int u, v;
        while(~scanf("%d%d", &N, &M)) {
                for(int i=1; i<=N; i++)
                        scanf("%d%d", &crd[i][0], &crd[i][1]);
                for(int i=1; i<=N; i++)
                        for(int j=1; j<=N; j++)
                                maps[i][j] = INF;
                for(int i=0; i<M; i++) {
                        scanf("%d%d", &u, &v);
                        maps[u][v] = dist(u, v);
                }
                double ans = prim(1);
                if(ans<0) printf("poor snoopy\n");
                else printf("%.2f\n", ans);
        }

        return 0;
}
