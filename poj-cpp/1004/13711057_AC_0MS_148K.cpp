#include <cstdio>

int main(){
    double sum, month;
    int t, i;
    while(scanf("%lf", &sum)!=EOF){
        for(i=0; i<11; i++){
            scanf("%lf", &month);
            sum += month;
        }
        sum /= 12;
        t = (int)(sum*100);
        sum = (double)t/100;
        printf("$%lg\n", sum);
    }
    return 0;
}
