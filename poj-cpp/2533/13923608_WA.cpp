#include <stdio.h>
#include <string.h>

int main(){
    int num[2000], sub[2000], i, j, maxs, N;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            scanf("%d", &num[i]);
        }
        for(i=0; i<N; i++) sub[i] = 1;
        for(i=1; i<N; i++){
            for(j=i; j>=0; j--){
                if(num[j]<=num[i]){
                    sub[i] = sub[j]+1;
                    break;
                }
            }
        }
        for(i=0, maxs=0; i<N; i++){
            if(sub[i]>maxs) maxs = sub[i];
        }
        printf("%d\n", maxs);
    }

    return 0;
}
