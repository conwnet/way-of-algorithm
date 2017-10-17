#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 1024;
const int INF = 0x3f3f3f3f;

int N;
double tx[maxn], ty[maxn], th[maxn];
double dis[maxn];
double maps[maxn][maxn], hei[maxn][maxn];
int vst[maxn];

double dist(int i, int j)
{
        double x = tx[i]-tx[j];
        double y = ty[i]-ty[j];
        return sqrt(x*x + y*y);
}


double prim(double r)
{
        double res = 0;
        memset(vst, 0, sizeof(vst));
        fill(dis, dis+N, INF);
        int s = 0;
        for(int i=1; i<N; i++) {
                vst[s] = 1;
                double mins = INF;
                int minf;
                for(int j=0; j<N; j++) {
                        if(!vst[j] && hei[s][j] - r*maps[s][j] < dis[j])
                                dis[j] = hei[s][j] - r*maps[s][j];
                        if(!vst[j] && dis[j] < mins) {
                                mins = dis[j];
                                minf = j;
                        }
                }
                s = minf;
                res += mins;
        }
        return res;
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++) {
                        scanf("%lf%lf%lf", &tx[i], &ty[i], &th[i]);
                }
                for(int i=1; i<N; i++) {
                        for(int j=0; j<i; j++) {
                                maps[i][j] = maps[j][i] =
                                dist(i, j);
                                hei[i][j] = hei[j][i] = fabs(th[i]-th[j]);
                        }
                }

                double l = 0;
                double r = 100;
                double m;
                while(r-l > 1e-5) {
                        m = (l+r)/2;
                        double res = prim(m);
                        //if(fabs(res) < 1e-5) break;
                        if(res > 1e-5) l = m;
                        else r = m;
                }
                printf("%.3f\n", l);
        }

        return 0;
}
