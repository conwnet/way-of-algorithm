#include <stdio.h>
#include <math.h>

const double d = (sqrt(5)+1)/2;

int main()
{
        int a, b, k;

        while(~scanf("%d%d", &a, &b)) {
                if(a>b) a^=b^=a^=b;
                k = b-a;
                if(a==(int)(d*k))
                        printf("0\n");
                else printf("1\n");
        }

        return 0;
}
