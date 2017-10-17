#include <stdio.h>

int root[128][128];
int maxn, Max, N;


void dfs(int pos);

int main(){
    int i, j;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            for(j=0; j<i+1; j++){
                scanf("%d", &root[i][j]);
            }
        }
        maxn = Max = 0;
        dfs(0);
        printf("%d\n", Max);
    }


    return 0;
}

void dfs(int pos){

    if(pos/128>=N){
        if(maxn>Max) Max = maxn;
        return ;
    }
    else{
        maxn += root[0][pos];
        dfs(pos+128);
        dfs(pos+129);
        maxn -= root[0][pos];
    }

}

