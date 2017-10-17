#include <cstdio>

int nflip(char map[], int n, int start, int nn);
int isWin(char map[]);
void change(char map[], int n);

int main(){
    char map[4][4];
    int i, j, count;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    for(i=0; i<16; i++){
        if(nflip(map[0], i, 0, 16-i)==1){
            printf("%d\n", i);
            return 0;
        };
    }
    printf("Impossible\n");

    return 0;
}

int nflip(char map[], int n, int start, int nn){
    int i;

    if(n==0){
        if(1==isWin(map)) return 1;
        else return 0;
    }
    else if(n==1){
        for(i=start; i<nn; i++){
            change(map ,i);
            if(isWin(map)==1) return 1;
            change(map ,i);
        }
    }
    else{
        for(i=start; i<nn; i++){
            change(map ,i);
            if(nflip(map, n-1, i+1, nn+1)==1) return 1;
            change(map ,i);
        }
    }
    return 0;
}


int isWin(char map[]){
    int i;
    for(i=0; i<15; i++){
        if(map[i]!=map[i+1]) return 0;
    }
    return 1;
}

void change(char a[], int n){
    int x, y;

    x = n%4;
    y = n/4;
    if(a[n]=='w') a[n] = 'b';
        else a[n] = 'w';
    if(x>0){
        if(a[n-1]=='w') a[n-1] = 'b';
        else a[n-1] = 'w';
    }
    if(x<3){
        if(a[n+1]=='w') a[n+1] = 'b';
        else a[n+1] = 'w';
    }
    if(y>0){
        if(a[n-4]=='w') a[n-4] = 'b';
        else a[n-4] = 'w';
    }
    if(y<3){
        if(a[n+4]=='w') a[n+4] = 'b';
        else a[n+4] = 'w';
    }

}
