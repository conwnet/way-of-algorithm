#include <stdio.h>

int main()
{
        char t1[30], t2[30], type[10];
        int m, ans = 0;

        while(scanf("%s", t1)) {
                if(t1[0]=='0') {
                        printf("%d\n", ans);
                        ans = 0;
                        continue;
                } else if(t1[0]=='#') break;
                scanf("%s%d%s", t2, &m, type);
                int t = 0;
                if(type[0]=='F') t = m*2;
                else if(type[0]=='B') t = (int)(m*1.5+0.5);
                else t = m;
                if(t<500) t = 500;
                ans += t;
        }

        return 0;
}
