#include <stdio.h>
#include <time.h>

int value[7];

int dfs(int n);

int main(){
    int i,
    sum, nCase = 0;

    while(scanf("%d%d%d%d%d%d", &value[1], &value[2], &value[3], &value[4], &value[5], &value[6])){
        if(!value[1] && !value[2] && !value[3] && !value[4] && !value[5] && !value[6]) break;
        printf("Collection #%d:\n", ++nCase);
        for(i=1; i<=6; i++){
if(value[i]>60){
            if(value[i]%2) value[i] = 61;
            else value[i] = 60;
}
        }
        sum = value[1]*1 + value[2]*2 + value[3]*3 + value[4]*4 + value[5]*5 + value[6]*6;
        if(!(sum%2) && dfs(sum>>1)) printf("Can be divided.\n\n");
        else printf("Can't be divided.\n\n");
    }
    return 0;
}

int dfs(int n){
    int i;

    if(n<0) return 0;
    if(n==0){
        return 1;
    }
    for(i=6; i>0; i--){
        if(value[i]>0){
            value[i] --;
            if(dfs(n-i)) return 1;
            value[i] ++;
        }
    }

    return 0;
}