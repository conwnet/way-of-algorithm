#include <cstdio>

int main(){
    int i;
    double sum=0, n;
    while(scanf("%lf", &n)){
        if(0==n) break;
        for(i=2; ; i++){
            sum += 1/(double)i;
            if(sum>n) break;
        }
        printf("%d card(s)\n", i-1);
        sum = 0;
    }
    return 0;
}
