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
int dcmp(double x) {
        if(fabs(x)<eps) return 0;
        else return x<0? -1 : 1;
}

bool operator == (const Point &a, const Point &b)
{
        return !dcmp(a.x-b.x) && !dcmp(a.y-b.y);
}

Point operator + (Point &A, Point &B)
{
        return Point(A.x+B.x, A.y+B.y);
}

Vector operator - (Point &A, Point &B)
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

Point dot[1024], ch[1024];
int N, R;

int main()
{
        double x, y;
        scanf("%d%d", &N, &R);
        for(int i=0; i<N; i++) {
                scanf("%lf%lf", &x, &y);
                dot[i] = Point(x, y);
        }
        int m = convex_hull(dot, N, ch);
        double ans = 0;
        for(int i=1; i<m; i++) {
                ans += dist(ch[i-1], ch[i]);
        }
        ans += dist(ch[0], ch[m-1]) + 3.1415*2*R;
        printf("%.0f\n", ans+0.5);

        return 0;
}







