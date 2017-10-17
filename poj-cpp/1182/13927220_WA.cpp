#include <stdio.h>
#include <string.h>

int anm[60000];

int findr(int a){
    return anm[a]==a?a:anm[a]=findr(anm[a]);
}

int main(){
    int boss[60000], i, N, K, cnt=0, op, a, b;

    memset(boss, 0, sizeof(boss));
    for(i=0; i<60000; i++) anm[i] = i;
    scanf("%d%d", &N, &K);
    while(K--){
        scanf("%d%d%d", &op, &a, &b);
        if(a>N || b>N) cnt++;
        else if(op==1){
            int x = findr(a);
            int y = findr(b);

            if(boss[x]==0){
                anm[x] = y;
            }
            else if(boss[y]==0){
                anm[y] = x;
            }
            else if(boss[x]==boss[y]);
            else cnt++;
        }
        else if(op==2){
            if(a==b){
                cnt++;
                continue;
            }
            int x = findr(a);
            int y = findr(b);

            if(boss[y]==0){
                boss[y] = x;
            }
            if(boss[x]==boss[findr(boss[y])]);
            else cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}