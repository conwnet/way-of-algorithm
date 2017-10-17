#include <stdio.h>

int maps[128][128], N, Max;

void GetSum();

int main(){
    int i, j;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                scanf("%d", &maps[i][j]);
            }
        }
        for(i=1; i<N; i++){
            maps[0][i] += maps[0][i-1];
        }
        for(i=1; i<N; i++){
            for(j=1; j<N; j++){
                maps[i][j] += maps[i][j-1];
            }
            for(j=0; j<N; j++){
                maps[i][j] += maps[i-1][j];
            }
        }
        for(i=0; i<N; i++){
            for(j=0; j<N; j++)
                printf("%d ", maps[i][j]);
            printf("\n");
        }
        GetSum();
        printf("%d\n", Max);
    }

    return 0;
}

void GetSum(){
    int minn, maxn, i, j, i1, j1;

    Max = maxn = maps[0][0];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            minn = maps[0][0];
            for(i1=0; i1<=i; i1++){
                for(j1=0; j1<=j; j1++){
                    if(maps[i1][j1]<minn) minn = maps[i1][j1];
                }
            }
            maxn = maps[i][j]-minn;
            if(maxn>Max) Max = maxn;
        }
    }
}