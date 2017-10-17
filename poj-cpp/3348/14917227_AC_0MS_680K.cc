#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
    Point(double x=0, double y=0):
        x(x), y(y) {}
};

typedef Point Vector;
const double eps = 1e-8;
const double PI = acos(-1.0);
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

Point get_line_intersection(Point P, Vector v, Point Q, Vector w)
{
        Vector u = P-Q;
        double t = (w ^ u) / (v ^ w);
        return P + v*t;
}

int convex_hull(Point *p, int n, Point *ch)
{
        sort(p, p+n);
        int m = 0;
        for(int i=0; i<n; i++) {
                while(m>1 && ((ch[m-1]-ch[m-2]) ^ (p[i]-ch[m-2])) <= 0)
                        m--;
                ch[m++] = p[i];
        }
        int k = m;
        for(int i=n-2; i>=0; i--) {
                while(m>k && ((ch[m-1]-ch[m-2]) ^ (p[i]-ch[m-2])) <= 0)
                        m--;
                ch[m++] = p[i];
        }
        if(n>1) m--;
        return m;
}

Point dot[10010], con[10010];
int N;

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%lf%lf", &dot[i].x, &dot[i].y);
        int n = convex_hull(dot, N, con);
        double S = 0;
        for(int i=1; i<n; i++) {
                S += con[i] ^ con[i-1];
        }
        S += con[0] ^ con[n-1];
        printf("%d\n", (int)fabs(S/100));

        return 0;
}