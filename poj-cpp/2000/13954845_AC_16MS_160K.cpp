#include <stdio.h>

int main()
{
        int n, i, sum, t, nn;

        while(scanf("%d", &n), n){
                sum = 0;
                for(i=0, nn=0, t=1; i<n; i++){
                        if(nn==0) nn = t;
                        sum += t;
                        nn--;
                        if(!(nn)){
                                t++;
                        }
                }
                printf("%d %d\n", n, sum);
        }

        return 0;
}
