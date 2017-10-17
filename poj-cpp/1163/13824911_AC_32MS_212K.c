#include <stdio.h>

int main(){
    int i, j, N, root[128][128];

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            for(j=0; j<i+1; j++){
                scanf("%d", &root[i][j]);
            }
        }

        for(i=N-2; i>=0; i--){
            for(j=0; j<=i; j++){
                root[i][j] += root[i+1][j]>root[i+1][j+1]?root[i+1][j]:root[i+1][j+1];
            }
        }

        printf("%d\n", root[0][0]);
    }

    return 0;
}