#include <stdio.h>
#include <math.h>

int main()
{
        int l, n, T, c;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &l, &n);
                double m = l/2.0, a = 1000001, b = 0;
                for(int i=0; i<n; i++) {
                        scanf("%d", &c);
                        if(fabs(m-c) < a) a = fabs(m-c);
                        if(fabs(m-c) > b) b = fabs(m-c);
                }
                printf("%d %d\n", (int)(m-a), (int)(m+b));
        }

        return 0;
}
