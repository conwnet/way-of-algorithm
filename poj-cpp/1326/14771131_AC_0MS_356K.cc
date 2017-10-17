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
                if(type[0]=='F') ans += m*2;
                else if(type[0]=='B') ans += (int)(m*1.5+0.5);
                else ans += m<500 ? 500 : m;
        }

        return 0;
}
