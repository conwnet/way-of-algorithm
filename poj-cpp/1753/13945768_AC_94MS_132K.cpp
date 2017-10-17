#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int isOk(int maps[][4])
{
    int i;

    for(i=1; i<16; i++){
        if(maps[0][i]!=maps[0][i-1]) return 0;
    }

    return 1;
}

int main()
{
    int maps[4][4], mapss[4][4], lst[16], arr[16], i, j, n=0;
    char t;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%c", &t);
            if(t=='b') maps[i][j] = 0;
            else maps[i][j] = 1;
        }
        getchar();
    }

    if(isOk(maps)){
        printf("0\n");
        return 0;
    }
    memset(lst, 0, sizeof(lst));
    for(i=15; i>=0; i--){
        lst[i] = 1;
        for(j=0; j<16; j++){
                arr[j] = lst[j];
        }
        do{
            for(j=0; j<16; j++){
                mapss[0][j] = maps[0][j];
            }
            for(j=0; j<16; j++){
                if(arr[j]){
                    mapss[0][j] = !mapss[0][j];
                    if(j>3) mapss[0][j-4] = !mapss[0][j-4];
                    if(j%4!=0) mapss[0][j-1] = !mapss[0][j-1];
                    if(j<12) mapss[0][j+4] = !mapss[0][j+4];
                    if(j%4!=3) mapss[0][j+1] = !mapss[0][j+1];
                }
            }
            if(isOk(mapss)){
                printf("%d\n", 16-i);
                return 0;
            }
        }while(next_permutation(arr, arr+16));
    }
    printf("Impossible\n");
    return 0;
}
