#include <stdio.h>

int main(){
    int refi[4][4];
    int i, j, t, cnt=0;
    char ch;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%c", &ch);
            if(ch=='-') refi[i][j] = 1;
            else refi[i][j] = 0;
        }
        getchar();
    }
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(refi[i][j]==0){
                refi[i][0] = !refi[i][0];
                refi[i][1] = !refi[i][1];
                refi[i][2] = !refi[i][2];
                refi[i][3] = !refi[i][3];
                refi[0][j] = !refi[0][j];
                refi[1][j] = !refi[1][j];
                refi[2][j] = !refi[2][j];
                refi[3][j] = !refi[3][j];
            }
        }
    }
    for(i=0; i<16; i++){
        if(refi[0][i]%2!=0) cnt++;
    }
    printf("%d\n", cnt);
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(refi[i][j]%2!=0) printf("%d %d\n", i+1, j+1);
        }
    }
    return 0;
}
