#include <stdio.h>

int isOk1(int maps[][4])
{
    int i, j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(!maps[i][j]) return 0;
        }
    }
    return 1;
}

int isOk2(int maps[][4])
{
    int i, j;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(maps[i][j]) return 0;
        }
    }
    return 1;
}

int main()
{
    int maps[4][4], mapss[4][4], i, j, n=0;
    char t;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%c", &t);
            if(t=='b') maps[i][j] = 0;
            else maps[i][j] = 1;
        }
        getchar();
    }

    if(isOk1(maps) || isOk2(maps)){
        printf("0\n");
        return 0;
    }

    for(i=1; i<(1<<16); i++){
        for(t=0; t<16; t++) mapss[0][t] = maps[0][t];
        for(j=0; j<16; j++){
            if((1<<j)&i){
                mapss[0][j] = !mapss[0][j];
                if(j>3) mapss[0][j-4] = !mapss[0][j-4];
                if(j%4!=0) mapss[0][j-1] = !mapss[0][j-1];
                if(j<12) mapss[0][j+4] = !mapss[0][j+4];
                if(j%4!=3) mapss[0][j+1] = !mapss[0][j+1];
            }
        }
        if(isOk1(mapss) || isOk2(mapss)){
            for(j=0; j<16; j++){
                if((1<<j)&i) n++;
            }
            printf("%d\n", n);
            return 0;
        }
    }
    printf("Impossible\n");
    return 0;
}
