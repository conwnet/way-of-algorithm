#include <stdio.h>

int maps[128][128]={0}, N, Max;

void GetSum();

int main(){
    int i, j;

    while(~scanf("%d", &N)){
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                scanf("%d", &maps[i][j]);
            }
        }
        for(i=2; i<=N; i++){
            maps[1][i] += maps[1][i-1];
        }
        for(i=2; i<=N; i++){
            for(j=2; j<=N; j++){
                maps[i][j] += maps[i][j-1];
            }
            for(j=1; j<=N; j++){
                maps[i][j] += maps[i-1][j];
            }
        }
        puts("");
        for(i=0; i<=N; i++){
            for(j=0; j<=N; j++){
                printf("%d ", maps[i][j]);
            }
            puts("");
        }
        GetSum();
        printf("%d\n", Max);
    }

    return 0;
}

void GetSum(){
    int max, i, j, x, y;

    max = Max = maps[1][1];
    for(i=1; i<=N; i++){
        for(j=1; j<=N; j++){
            for(x=0; x<i; x++){
                for(y=0; y<j; y++){
                    max = maps[i][j]-maps[x][j]-maps[i][y]+maps[x][y];
                    if(max>Max) Max = max;
                }
            }
        }
    }
}


