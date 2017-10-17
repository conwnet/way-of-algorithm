#include <stdio.h>

int main(){
    int refi[4][4], cpy[4][4]={0};
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
                cpy[i][0]++;
                cpy[i][1]++;
                cpy[i][2]++;
                cpy[i][3]++;
                cpy[0][j]++;
                cpy[1][j]++;
                cpy[2][j]++;
                cpy[3][j]++;
                cpy[i][j]--;
            }
        }
    }
    for(i=0; i<16; i++){
        if(cpy[0][i]%2!=0) cnt++;
    }
    printf("%d\n", cnt);
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(cpy[i][j]%2!=0) printf("%d %d\n", i+1, j+1);
        }
    }
    return 0;
}
