#include <stdio.h>

int maps[128][128], N, maxn;

void GetSum(int sl, int sr, int el, int er);

int main(){
    int i, j;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                scanf("%d", &maps[i][j]);
            }
        }
        GetSum(0, 0, 0, 0);
        printf("%d\n", maxn);
    }

    return 0;
}

void GetSum(int sl, int sr, int el, int er){
    int si, sj, ei, ej, sum, i, j;

    maxn = maps[0][0];
    for(si=0; si<N; si++){
        for(sj=0; sj<N; sj++){
            for(ei=si; ei<N; ei++){
                for(ej=sj; ej<N; ej++){
                    sum = 0;
                    for(i=si; i<=ei; i++){
                        for(j=sj; j<=ej; j++){
                            sum += maps[i][j];
                        }
                    }
                    if(sum>maxn) maxn = sum;
                }
            }
        }
    }
}