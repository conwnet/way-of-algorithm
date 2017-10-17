#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0):
        x(x), y(y) {}
};

typedef Point Vector;
const double eps = 1e-8;
int dcmp(double x) {
        if(fabs(x)<eps) return 0;
        else return x<0? -1 : 1;
}

bool operator == (const Point &a, const Point &b)
{
        return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}

Point operator + (Point A, Point B)
{
        return Point(A.x+B.x, A.y+B.y);
}

Vector operator - (Point A, Point B)
{
        return Vector(A.x-B.x, A.y-B.y);
}

Vector operator * (Vector A, double n)
{
        return Vector(A.x*n, A.y*n);
}

double operator * (Vector A, Vector B)
{
        return A.x*B.x + A.y*B.y;
}

double operator ^ (Vector A, Vector B)
{
        return A.x*B.y - A.y*B.x;
}

bool operator < (const Point &A, const Point &B) {
        return A.x<B.x || (A.x==B.x && A.y<B.y);
}

double dist(Point A, Point B)
{
        return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

Point la[6000], lb[6000];
int N, M, cnt[6000];
double X1, X2, Y1, Y2;

int main()
{
        double u, l, x, y;
        while(scanf("%d", &N) && N) {
                scanf("%d%lf%lf%lf%lf", &M, &X1, &Y1, &X2, &Y2);
                la[0] = Point(X1, Y1);
                lb[0] = Point(X1, Y2);
                for(int i=1; i<=N; i++) {
                        scanf("%lf%lf", &u, &l);
                        la[i] = Point(u, Y1);
                        lb[i] = Point(l, Y2);
                }
                la[++N] = Point(X2, Y1);
                la[N] = Point(X2, Y2);
                memset(cnt, 0, sizeof(cnt));
                while(M--) {
                        scanf("%lf%lf", &x, &y);
                        Point t = Point(x, y);
                        int l = 0, r = N;
                        while(l<r) {
                                int m = (l+r)>>1;
                                if(((t-la[m])^(lb[m]-la[m])) < 0)
                                        l = m+1;
                                else r = m;
                        }
                        cnt[l-1]++;
                }
                for(int i=0; i<N; i++) {
                        printf("%d: %d\n", i, cnt[i]);
                }
                printf("\n");
        }

        return 0;
}



