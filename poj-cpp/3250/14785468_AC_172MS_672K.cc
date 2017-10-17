#include <stdio.h>

int que[85000], N, top, cnt;

int main()
{
        int a;
        unsigned long long ans = 0;
        top = cnt = 0;
        scanf("%d", &N);
        while(N--) {
                scanf("%d", &a);
                while(cnt && que[top-1]<=a) {
                        top--; cnt--;
                }
                ans += cnt;
                que[top++] = a; cnt++;
        }
        printf("%lld\n", ans);

        return 0;
}

