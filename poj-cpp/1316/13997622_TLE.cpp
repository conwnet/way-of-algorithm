#include <stdio.h>

int main()
{
        int i, j, sum, faild;

        for(i=1; i<=10000; i++){
                faild = 0;
                for(j=1; j<i; j++){
                        int t = j;
                        sum = j;
                        while(t>0){
                                sum += t%10;
                                t /= 10;
                        }
                        if(sum==i){
                                faild = 1;
                                break;
                        }
               }
               if(!faild) printf("%d\n", i);
        }

        return 0;
}
