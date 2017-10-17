#include <stdio.h>
#include <math.h>

struct Point {
        double x, y;
} p, q;

double Cross(Point A, Point B)
{
        return A.x*B.y - B.x*A.y;
}
typedef long long ll;
char str[1000010];
int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%s", str);
                p.x = p.y = 0;
                double ans = 0;
                for(int i=0; str[i]!='5'; i++) {
                        if(str[i]=='8') q = (Point){p.x, p.y+1};
                        else if(str[i]=='2') q = (Point){p.x, p.y-1};
                        else if(str[i]=='6') q = (Point){p.x+1, p.y};
                        else if(str[i]=='4') q = (Point){p.x-1, p.y+1};
                        else if(str[i]=='9') q = (Point){p.x+1, p.y+1};
                        else if(str[i]=='7') q = (Point){p.x-1, p.y+1};
                        else if(str[i]=='3') q = (Point){p.x+1, p.y-1};
                        else if(str[i]=='1') q = (Point){p.x-1, p.y-1};
                        ans += Cross(p, q);
                        ///printf("%f %f %f %f %f\n", p.x, p.y, q.x, q.y, ans);
                        p = q;
                }
                ans = fabs(ans/2);
                if(ans - (ll)ans > 0.2)
                        printf("%lld.5\n", (ll)ans);
                else printf("%lld\n", (ll)ans);
        }

        return 0;
}
