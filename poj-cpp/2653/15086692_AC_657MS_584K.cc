#include <stdio.h>
#include <string.h>
#include <list>

using namespace std;

struct Point {
        double x, y;
        Point(double x, double y):
                x(x), y(y) {}
        Point() {}
};

const int maxn = 100010;
int N;

double Cross(Point A, Point B)
{
        return A.x*B.y - A.y*B.x;
}

Point operator - (const Point& A, const Point& B)
{
        return Point(A.x-B.x, A.y-B.y);
}

struct Seg {
        Point a, b;
        int num;
};
int SegInt(Seg A, Seg B)
{

        double c1 = Cross(A.b-A.a, B.a-A.a);
        double c2 = Cross(A.b-A.a, B.b-A.a);
        double c3 = Cross(B.b-B.a, A.a-B.a);
        double c4 = Cross(B.b-B.a, A.b-B.a);
        return c1*c2<0 && c3*c4<0;
}


list<Seg> L;

int main()
{
        Seg S;
        list<Seg>::iterator it, p;
        while(~scanf("%d", &N) && N) {
                L.clear();
                for(int i=1; i<=N; i++) {
                        scanf("%lf%lf%lf%lf", &S.a.x, &S.a.y,
                                      &S.b.x, &S.b.y);
                        S.num = i;
                        for(it=L.begin(); it!=L.end(); ) {
                                if(SegInt(*it, S)) {
                                        p = it++;
                                        L.erase(p);
                                } else it++;
                        }
                        L.push_back(S);
                }
                it=L.begin();
                printf("Top sticks: %d", it->num);
                for(it++; it!=L.end(); it++)
                        printf(", %d", it->num);
                printf(".\n");
        }

        return 0;
}












