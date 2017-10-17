#include <stdio.h>

int main()
{
        int num, n, T;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &num, &n);
                int ans = 0;
                for(int i=2; i*(1+i)/2<=n; i++) {
                        if(0==(n-i*(1+i)/2)%i) ans++;
                }
                printf("%d %d\n", num, ans);
        }

        return 0;
}
