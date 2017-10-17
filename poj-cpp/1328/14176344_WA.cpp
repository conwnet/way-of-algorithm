#include <stdio.h>
#include <math.h>
#include <algorithm>
#define INF 999999999

using namespace std;

struct Point {
        double y;
        double x;
        double l;
        double r;
        int v;
        Point(double a, double b) {
                x = a;
                y = b;
                v = 0;
        }
        Point(){v=0;}
        bool operator < (const Point& b) const {
                if(x==b.x) return y<b.y;
                return x<b.x;
        }
        double dis(Point b) {
                double m = b.y-y;
                double n = b.x-x;
                return sqrt(m*m+n*n);
        }
}dot[1100];

int main()
{
        int M, N, nCase=0, i, j, ans, faild;
        double  l, r, mid;

        while(scanf("%d%d", &M, &N)) {
                if(M==0 && N==0) break;
                printf("Case %d: ", ++nCase);
                faild = 0;
                for(i=0; i<M; i++) {
                        scanf("%lf%lf", &dot[i].x, &dot[i].y);
                        dot[i].v = 0;
                        if(dot[i].y>N) faild = 1;
                }
                if(faild==1) {
                        printf("-1");
                        continue;
                }
                sort(dot, dot+M);
                for(i=0; i<M; i++) {
                        l = dot[i].x-N;
                        r = dot[i].x;
                        for(j=0; j<100; j++) {
                                mid = (l+r)/2;
                                if(dot[i].dis(Point(mid, 0))>=N) l = mid;
                                else r = mid;
                        }
                        dot[i].l = mid;

                        l = dot[i].x;
                        r = dot[i].x+N;
                        for(j=0; j<100; j++) {
                                mid = (l+r)/2;
                                if(dot[i].dis(Point(mid, 0))<=N) l = mid;
                                else r = mid;
                        }
                        dot[i].r = mid;
                }
                ans = 0;
                for(i=0; i<M; i++) {
                        if(!dot[i].v) ans++;
                        for(j=i+1; j<M; j++) {
                                if(dot[j].l<=dot[i].r) dot[j].v = 1;
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}
