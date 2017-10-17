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

double get_rate(Point A, Point B)
{
        if(B.x==A.x) return -1;
        return (B.y-A.y) / (B.x-A.x);
}

Point dot[4];

int main()
{
        int T;
        scanf("%d", &T);
        printf("INTERSECTING LINES OUTPUT\n");
        while(T--) {
                for(int i=0; i<4; i++)
                        scanf("%lf%lf", &dot[i].x, &dot[i].y);
                double r1 = get_rate(dot[1], dot[0]);
                double r2 = get_rate(dot[3], dot[2]);
                if(fabs(r1-r2)<eps) {
                        if(fabs(get_rate(dot[2], dot[1])-get_rate(dot[1], dot[0]))<eps) {
                                printf("LINE\n");
                        } else printf("NONE\n");
                } else {
                        Point t = get_line_intersection(dot[0],
                                dot[1]-dot[0], dot[2], dot[3]-dot[2]);
                        printf("POINT %.2f %.2f\n", t.x, t.y);
                }
        }
        printf("END OF OUTPUT\n");

        return 0;
}






