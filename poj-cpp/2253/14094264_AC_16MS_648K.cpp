#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

double w[210*210];
int N, u[210*210], v[210*210], r[210*210], x[210], y[210], cnt, p[210*210];

int findp(int u)
{
        return p[u]==u?u:p[u]=findp(p[u]);
}
double kruskal();
int cmp(int a, int b)
{
        return w[a]<w[b];
}

int main()
{
        int i, j, nCase = 1;

        while(scanf("%d", &N) && N) {
                for(i=0; i<N; i++) {
                        scanf("%d%d", &x[i], &y[i]);
                }
                cnt = 0;
                for(i=0; i<N; i++) {
                        for(j=0; j<i; j++) {
                                u[cnt] = i;
                                v[cnt] = j;
                                double t1 = (double)x[i]-x[j];
                                double t2 = (double)y[i]-y[j];
                                w[cnt++] = sqrt(t1*t1 + t2*t2);
                        }
                }
                printf("Scenario #%d\nFrog Distance = ", nCase++);
                printf("%.3lf\n\n", kruskal());
        }

        return 0;
}

double kruskal()
{
        int i;
        for(i=0; i<=cnt; i++) r[i] = p[i] = i;
        sort(r, r+cnt, cmp);
        for(i=0; i<cnt; i++) {
                int t = r[i];
                int x = findp(u[t]);
                int y = findp(v[t]);

                if(x!=y) {
                        p[x] = y;
                }
                x = findp(0);
                y = findp(1);
                if(x==y)
                        break;
        }
        return w[r[i]];
}
