#include <stdio.h>

int N, M, cnt;

int solve(int s, int n, int m);

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);
        cnt = 0;
        solve(0, N, M);
        printf("%d\n", cnt);
    }

    return 0;
}

int solve(int s, int n, int m){
    int i;

    if(m==1 && n>=s){
        cnt++;
    }
    else{
        for(i=0; i<=n; i++){
            if(i<s) continue;
            if((n-i)/(m-1)<i) break;
            solve(i, n-i, m-1);
        }
    }
    return 1;
}