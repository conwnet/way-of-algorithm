#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);
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

Point dot[3];

int main()
{
        while(~scanf("%lf%lf%lf%lf%lf%lf", &dot[0].x, &dot[0].y, &dot[1].x, &dot[1].y,
                &dot[2].x, &dot[2].y)) {
                double a = dist(dot[0], dot[1]);
                double b = dist(dot[1], dot[2]);
                double c = dist(dot[2], dot[0]);
                double S4 = sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a));
                double R = a*b*c/S4;
                printf("%.2f\n", 2*R*PI);
        }

        return 0;
}
