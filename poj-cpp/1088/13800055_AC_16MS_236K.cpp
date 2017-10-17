#include <stdio.h>
#include <string.h>

int Map[128][128], m, n, omax, step[128][128];
int dfs(int y, int x, int Max);


int main(){
    int i, j, Max, rzt;

    while(scanf("%d%d", &m, &n)!=EOF){
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                scanf("%d", &Map[i][j]);
            }
        }
        memset(step, 0, m*n*4);
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                omax = 0;
                dfs(i, j, 1);
                step[i][j] = omax;
            }
        }
        rzt = 0;
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(step[i][j]>rzt) rzt = step[i][j];
            }
        }
        printf("%d\n", rzt);
    }

    return 0;
}

int dfs(int y, int x, int Max){
    if(step[y][x]!=0){
        Max--;
        Max += step[y][x];
        if(Max>omax) omax = Max;
        return Max;
    }
    if(y-1>=0 && Map[y-1][x]<Map[y][x]){
        Max++;;
        dfs(y-1, x, Max);
        Max--;
    }
    if(x-1>=0 && Map[y][x-1]<Map[y][x]){
        Max++;
        dfs(y, x-1, Max);
        Max--;
    }
    if(y+1<m && Map[y+1][x]<Map[y][x]){
        Max++;
        dfs(y+1, x, Max);
        Max--;
    }
    if(x+1<n && Map[y][x+1]<Map[y][x]){
        Max++;
        dfs(y, x+1, Max);
        Max--;
    }
    if(Max>omax) omax = Max;
    return Max;
}
