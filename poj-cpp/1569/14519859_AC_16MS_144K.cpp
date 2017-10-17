#include <stdio.h>
#include <math.h>
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

Vector operator - (Point &A, Point &B) {
        return Vector(A.x-B.x, A.y-B.y);
}

bool operator < (const Point &a, const Point &b) {
        return a.x<b.x || (a.x==b.x && a.y<b.y);
}

double operator ^ (Vector A, Vector B)
{
        return A.x*B.y - A.y*B.x;
}

int side_of_line(Point a, Point b, Point p)
{
        double res = (b-a) ^ (p-a);
        if(!dcmp(res)) return 0;
        if(res > 0) return 1;
        return -1;
}

Point dot[20];
int r[20];

int main()
{
        int N, a, b, c;
        double ans;

        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++) {
                        getchar();
                        r[i] = getchar();
                        scanf("%lf%lf", &dot[i].x, &dot[i].y);
                }
                ans = -1;
                for(int i=0; i<N; i++) {
                        for(int j=i+1; j<N; j++) {
                                for(int k=j+1; k<N; k++) {
                                        double t = (dot[j]-dot[i]) ^ (dot[k]-dot[j]);
                                        if(t==0) continue;
                                        int l;
                                        for(l=0; l<N; l++) {
                                                if(l==i || l==j || l==k) continue;
                                                if(t>0) {
                                                        if(side_of_line(dot[i], dot[j], dot[l])>=0 &&
                                                           side_of_line(dot[j], dot[k], dot[l])>=0 &&
                                                           side_of_line(dot[k], dot[i], dot[l])>=0)
                                                                break;
                                                } else {
                                                        if(side_of_line(dot[i], dot[j], dot[l])<=0 &&
                                                           side_of_line(dot[j], dot[k], dot[l])<=0 &&
                                                           side_of_line(dot[k], dot[i], dot[l])<=0)
                                                                break;
                                                }
                                        }
                                        if(l!=N) continue;
                                        t = fabs(dot[i]-dot[j] ^ dot[k]-dot[j]);
                                        if(t>ans) {
                                                ans = t;
                                                a = i;
                                                b = j;
                                                c = k;
                                        }
                                }
                        }
                }
                printf("%c%c%c\n", r[a], r[b], r[c]);
        }

        return 0;
}
