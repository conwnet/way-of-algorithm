#include <stdio.h>

int que[85000], N, top, cnt;

int main()
{
        int a, ans = 0;
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
        printf("%d\n", ans);

        return 0;
}


