#include <stdio.h>

int main()
{
        int cnt, T, N, t;
        char str[128];

        while(scanf("%d%d", &T, &N) && T) {
                cnt = 0;
                for(int i=0; i<T; i++) {
                        scanf("%s%d", str, &t);
                        cnt += t;
                }
                printf("%d\n", N*3-cnt);
        }

        return 0;
}
