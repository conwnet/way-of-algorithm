#include <stdio.h>

typedef long long ll;

int main()
{
        int N;
        ll a, b, h, ans = 0;
        scanf("%d", &N);
        while(N--) {
                scanf("%lld%lld%lld", &a, &b, &h);
                ans += (b-a)*h;
        }
        printf("%lld\n", ans-1);

        return 0;
}
