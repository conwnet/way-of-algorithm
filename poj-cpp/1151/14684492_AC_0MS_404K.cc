#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Edge {
        double x;
        int y1, y2, t;
        Edge(double a, int b, int c, int d):
                x(a), y1(b), y2(c), t(d) {}
        Edge() {}
};

double y[256];

/***********/

double len[1024];
int cnt[1024];

/**
void push_down(int o, int L, int R)
{
        lazy[o*2] = lazy[o*2+1] = lazy[o];
        cnt[o*2] += lazy[o];
        cnt[o*2+1] += lazy[o];
        lazy[o] = 0;
        int M = (L+R)>>1;
        len[o*2] = (cnt[o*2] ? y[M]-y[L-1] : 0);
        len[o*2+1] = (cnt[o*2+1] ? y[R]-y[M-1] : 0);
}
*/

void update(int o, int L, int R, int l, int r)
{
        if(l<=L && r>=R) {
                len[o] = y[R]-y[L];
                cnt[o]++;
                return ;
        }
        int M = (L+R)>>1;
        if(l<M) update(o*2, L, M, l, r);
        if(r>M) update(o*2+1, M, R, l, r);
        if(!cnt[o])
                len[o] = len[o*2]+len[o*2+1];
}

void del(int o, int L, int R, int l, int r)
{
        if(l<=L && r>=R) {
                cnt[o]--;
                if(cnt[o]==0)
                        if(L==R) len[o] = 0;
                        else len[o] = len[o*2]+len[o*2+1];
                return ;
        }
        int M = (L+R)>>1;
        if(l<M) del(o*2, L, M, l, r);
        if(r>M) del(o*2+1, M, R, l, r);
        if(!cnt[o])
                len[o] = len[o*2]+len[o*2+1];
}

/***********/


int cmp(Edge a, Edge b)
{
        return a.x < b.x;
}

Edge edge[256];
double pos[128][4];
int main()
{
        int N, n, yc, ec, nCase = 0;

        while(scanf("%d", &N) && N) {
                yc = 1;
                ec = 0;
                for(int i=0; i<N; i++) {
                        scanf("%lf%lf%lf%lf", &pos[i][0], &pos[i][1],
                               &pos[i][2], &pos[i][3]);
                        y[yc++] = pos[i][1]; y[yc++] = pos[i][3];
                }
                sort(y, y+yc);
                n = unique(y+1, y+yc) - y;
                y[0] = y[1];
                for(int i=0; i<N; i++) {
                        for(int j=1; j<n; j++) {
                                if(fabs(pos[i][1]-y[j]) < 1e-5)
                                        edge[ec].y1 = edge[ec+1].y1 = j;
                                if(fabs(pos[i][3]-y[j]) < 1e-5)
                                        edge[ec].y2 = edge[ec+1].y2 = j;
                        }
                        edge[ec].x = pos[i][0];
                        edge[ec].t = 0;
                        edge[ec+1].x = pos[i][2];
                        edge[ec+1].t = 1;
                        ec = ec+2;
                }
                memset(len, 0, sizeof(len));
                memset(cnt, 0, sizeof(cnt));
                double S = 0, prev = 0;
                sort(edge, edge+ec, cmp);
                for(int i=0; i<ec; i++) {
                        if(0==edge[i].t) {
                                S += (edge[i].x-prev)*len[1];
                                update(1, 1, n-1, edge[i].y1, edge[i].y2);
                                prev = edge[i].x;
                        } else {
                                S += (edge[i].x-prev)*len[1];
                                prev = edge[i].x;
                                del(1, 1, n-1, edge[i].y1, edge[i].y2);
                        }
                }
                printf("Test case #%d\n", ++nCase);
                printf("Total explored area: %.2f\n\n", S);

        }

        return 0;
}
