#include <stdio.h>
#include <math.h>
#define eps 1e-8

struct Point {
        double x, y;
        Point(double a, double b):
                x(a), y(b) {}
        Point() {}
        Point operator + (Point A) {
                return Point(x+A.x, y+A.y);
        }
};

double a, b, c, d, e, f, g, h;

int main()
{
        Point pa, pb, s;

        while(~scanf("%lf%lf%lf%lf", &a, &b, &c, &d)) {
                scanf("%lf%lf%lf%lf", &e, &f, &g, &h);
                if(fabs(e-a)<eps && fabs(f-b)<eps) {
                        s = Point(a, b);
                        pa = Point(c-a, d-b);
                        pb = Point(g-e, h-f);
                } else if(fabs(c-e)<eps && fabs(d-f)<eps) {
                        s = Point(c, d);
                        pa = Point(a-c, b-d);
                        pb = Point(g-e, h-f);
                } else if(fabs(g-a)<eps && fabs(h-b)<eps) {
                        s = Point(a, b);
                        pa = Point(c-a, d-b);
                        pb = Point(e-g, f-h);
                } else if(fabs(g-c)<eps && fabs(d-h)<eps) {
                        s = Point(c, d);
                        pa = Point(a-c, b-d);
                        pb = Point(e-g, f-h);
                }
                Point pc = pa+pb;
                printf("%.3lf %.3lf\n", s.x+pc.x, s.y+pc.y);
        }

        return 0;
}
