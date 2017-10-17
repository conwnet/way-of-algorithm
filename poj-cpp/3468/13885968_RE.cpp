#include <stdio.h>

long long arr[110000];

int main(){
    long long N, Q, i, a, b, c, t;
    char Cmd[10];

    scanf("%d%d", &N, &Q);
    scanf("%lld", &arr[0]);
    for(i=1; i<N; i++){
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
    }
    while(Q--){
        scanf("%s", Cmd);
        if(Cmd[0]=='Q'){
            scanf("%d%d", &a, &b);
            printf("%lld\n", arr[b-1]-arr[a-2]);
        }
        else{
            scanf("%d%d%lld", &a, &b, &c);
            t = c;
            for(i=a-1; i<b; i++){
                arr[i] += t;
                t += c;
            }
        }
    }

    return 0;
}