#include <stdio.h>

int solve(int n, int k);

int main(){
    int k, i, t;

    while(scanf("%d", &k), k){
t=k*2;
        for(i=1; ; i++){
if(i%t<k && k!=1) continue;
            if(solve(k, i)) break;
        }
        printf("%d\n", i);
    }

    return 0;
}

int solve(int n, int k){
    int i, t, sum;
    sum = n*2;
    for(i=0, t=-1; i<n; i++){
        t = (t+k)%sum;
        if(t<n) return 0;
        t--;
        sum--;
    }
   return 1;
}

