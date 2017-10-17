#include <stdio.h>

int main()
{
        int N, a, b, c;

        scanf("%d", &N);
        while(N--) {
                scanf("%d%d%d", &a, &b, &c);
                if(a==b-c) puts("does not matter");
                else if(a>b-c) puts("do not advertise");
                else puts("advertise");
        }

        return 0;
}
