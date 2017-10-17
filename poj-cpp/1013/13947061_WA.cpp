#include <stdio.h>
#include <string.h>

int main()
{
    char lcmd[4][10], rcmd[4][10], cmd[4][10];
    int hl, j, i, nCase, coin[15], t;

    scanf("%d", &nCase);
    while(nCase--){
        memset(coin, -1, sizeof(coin));

        for(i=0; i<3; i++){
            scanf("%s%s%s", lcmd[i], rcmd[i], cmd[i]);

            if(cmd[i][0]=='e'){
                for(j=0; lcmd[i][j]!='\0'; j++){
                    coin[lcmd[i][j]-'A'] = 1;
                }
                for(j=0; rcmd[i][j]!='\0'; j++){
                    coin[rcmd[i][j]-'A'] = 1;
                }
            }else{
                for(j=0; lcmd[i][j]!='\0'; j++){
                    if(coin[lcmd[i][j]-'A']!=1) coin[lcmd[i][j]-'A'] = 0;
                }
                for(j=0; rcmd[i][j]!='\0'; j++){
                    if(coin[lcmd[i][j]-'A']!=1) coin[rcmd[i][j]-'A'] = 0;
                }
            }
        }

        for(i=0; i<12; i++){
            if(coin[i]==0) break;
        }
        t = i;
        for(i=0, hl=0; i<3; i++){
            if(cmd[i][0]=='e') continue;
            for(j=0; lcmd[i][j]!='\0'; j++){
                if(lcmd[i][j]==t+'A'){
                    hl = !hl;
                    break;
                }
            }
            if(cmd[i][0]=='u') hl = !hl;
            break;
        }

        printf("%c is the counterfeit coin and it is %s.\n", t+'A', hl?"light":"heavy" );
    }
    return 0;
}
