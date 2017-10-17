#include <stdio.h>

int main()
{
        int N, s, t, sum, b;

        while(scanf("%d", &N)){
                if(N==-1) break;
                sum = 0;
                t = 0;
                while(N--){
                        scanf("%d%d", &s, &b);
                        sum += s*(b-t);
                        t = b;
                }
                printf("%d miles\n", sum);
        }

        return 0;
}
