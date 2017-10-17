#include <stdio.h>
#include <math.h>

typedef long long ll;
struct Point {
        ll x, y;
} p, q;

ll Cross(Point A, Point B)
{
        return A.x*B.y - B.x*A.y;
}

char str[1000010];
int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%s", str);
                p.x = p.y = 0;
                ll ans = 0;
                for(int i=0; str[i]!='5'; i++) {
                        if(str[i]=='8') q = (Point){p.x, p.y+1};
                        else if(str[i]=='2') q = (Point){p.x, p.y-1};
                        else if(str[i]=='6') q = (Point){p.x+1, p.y};
                        else if(str[i]=='4') q = (Point){p.x-1, p.y};
                        else if(str[i]=='9') q = (Point){p.x+1, p.y+1};
                        else if(str[i]=='7') q = (Point){p.x-1, p.y+1};
                        else if(str[i]=='3') q = (Point){p.x+1, p.y-1};
                        else if(str[i]=='1') q = (Point){p.x-1, p.y-1};
                        ans += Cross(p, q);
                        ///printf("%f %f %f %f %f\n", p.x, p.y, q.x, q.y, ans);
                        p = q;
                }
                if(ans<0) ans = -ans;
                if(ans&1) printf("%lld.5\n", ans>>1);
                else printf("%lld\n", ans>>1);
        }

        return 0;
}
