#include <stdio.h>

struct Point {
        double x, y;
        Point(double a, double b):
                x(a), y(b) {}
        Point() {}
        Point operator + (Point A) {
                return Point(x+A.x, y+A.y);
        }
};

double a, b, c, d;

int main()
{
        while(~scanf("%lf%lf%lf%lf", &a, &b, &c, &d)) {
                Point pa = Point(a-c, b-d);
                scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
                Point pb = Point(c-a, d-b);
                Point pc = pa+pb;
                printf("%.3lf %.3lf\n", a+pc.x, b+pc.y);
        }

        return 0;
}
