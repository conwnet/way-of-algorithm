#include <stdio.h>

int maps[128][128], N, Max, maxs[128][128];

void GetSum();

int main(){
    int i, j;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                scanf("%d", &maps[i][j]);
            }
        }
        for(i=0; i<N; i++){
            maxs[i][0] = maps[i][0];
        }
        for(i=1; i<N; i++){
            maxs[0][i] = maxs[0][i-1]+maps[0][i];
        }
        for(i=1; i<N; i++){
            for(j=1; j<N; j++){
                maxs[i][j] = maxs[i][j-1]+maps[i][j];
            }
            for(j=0; j<N; j++){
                maxs[i][j] += maxs[i-1][j];
            }
        }
        GetSum();
        printf("%d\n", Max);
    }

    return 0;
}

void GetSum(){
    int max, min, i, j, i1, j1, mi, mj;

    max = Max = maxs[0][0];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            min = maxs[0][0];
            for(i1=0; i1<=i; i1++){
                for(j1=0; j1<=j; j1++){
                    if(maxs[i1][j1]<=min){
                        if(((i1==i)^(j1==j))&&maps[i1][j1]<0&&maxs[i1][j1]==min) continue;
                        min = maxs[i1][j1];
                        mi = i1;
                        mj = j1;
                    }
                }
            }
            max = maxs[i][j]-min;
            if(!((mi==i)^(mj==j))) max += maps[mi][mj];
            if(max>Max){
                Max = max;
            }
        }
    }
}

