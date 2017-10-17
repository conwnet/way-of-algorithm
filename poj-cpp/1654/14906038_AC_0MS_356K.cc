#include <stdio.h>

typedef long long ll;
int main()
{
        int T, ch, px, py, qx, qy;
        scanf("%d", &T);
        while(T--) {
                px = py = 0;
                ll ans = 0;
                getchar();
                while((ch=getchar())!='5') {
                        if(ch=='8') { qx = px; qy = py+1; }
                        else if(ch=='2') { qx = px; qy = py-1; }
                        else if(ch=='6') { qx = px+1; qy = py; }
                        else if(ch=='4') { qx = px-1; qy = py; }
                        else if(ch=='9') { qx = px+1; qy = py+1; }
                        else if(ch=='7') { qx = px-1; qy = py+1; }
                        else if(ch=='3') { qx = px+1; qy = py-1; }
                        else if(ch=='1') { qx = px-1; qy = py-1; }
                        ans += px*qy - py*qx;
                        px = qx; py = qy;
                }
                if(ans<0) ans = -ans;
                if(ans&1) printf("%lld.5\n", ans>>1);
                else printf("%lld\n", ans>>1);
        }

        return 0;
}
