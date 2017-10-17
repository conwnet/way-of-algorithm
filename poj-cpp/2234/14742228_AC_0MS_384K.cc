#include <stdio.h>

int main()
{
        int n, a, b;

        while(~scanf("%d", &n)) {
                scanf("%d", &a);
                for(int i=1; i<n; i++) {
                        scanf("%d", &b);
                        a ^= b;
                }
                if(a) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}
