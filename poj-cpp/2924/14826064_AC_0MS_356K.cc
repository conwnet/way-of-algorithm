#include <stdio.h>
typedef long long ll;

int main()
{
        int T;
        ll s, a, b;
        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                printf("Scenario #%d:\n", nC);
                scanf("%lld%lld", &a, &b);
                printf("%lld\n\n", (a+b)*(b-a+1)/2);
        }
}
