#include <stdio.h>
#include <stdlib.h>

int main()
{
        int n, a, b, faild;

        while(~scanf("%d", &n)) {
                faild = 0;
                if(n>0) scanf("%d", &a);
                for(int k=1; k<n; k++) {
                        scanf("%d", &b);
                        int c = abs(b-a);
                        if(!(c>0 && c<n))
                                faild = 1;
                        a = b;
                }
                printf("%s\n", faild ? "Not jolly" : "Jolly");
        }

        return 0;
}
