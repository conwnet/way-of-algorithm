#include <stdio.h>
#include <string.h>

char lcmd[4][10], rcmd[4][10], cmd[4][10];

int isOk(char ch);

int main()
{
    char tc;
    int hl, j, i, nCase, coin[15];

    scanf("%d", &nCase);
    while(nCase--){
        memset(coin, -1, sizeof(coin));

        for(i=0; i<3; i++){
            scanf("%s%s%s", lcmd[i], rcmd[i], cmd[i]);
            for(j=0; lcmd[i][j]!='\0'; j++){
                coin[lcmd[i][j]-'A'] = 0;
            }
            for(j=0; rcmd[i][j]!='\0'; j++){
                coin[rcmd[i][j]-'A'] = 0;
            }
        }

        for(i=0; i<12; i++){
            if(coin[i]==0){
                tc = i+'A';
                if(hl=isOk(tc)) break;
            }
        }

        printf("%c is the counterfeit coin and it is %s\n", tc, hl<0?"light":"heavy" );
    }
    return 0;
}

int isOk(char ch){
    int i, j, jd=2;

    for(i=0; i<3; i++){
        for(j=0; lcmd[i][j]!='\0'; j++){
            if(lcmd[i][j]==ch){
                if(cmd[i][0]=='u'){
                    if(jd!=2 && jd!=1) return 0;
                    else jd = 1;
                }
                else if(cmd[i][0]=='d'){
                    if(jd!=2 && jd!=-1) return 0;
                    else jd = -1;
                }
                else{
                    if(jd!=2 && jd!=0) return 0;
                    else jd = 0;
                }
            }
            else if(rcmd[i][j]==ch){
                if(cmd[i][0]=='u'){
                    if(jd!=2 && jd!=-1) return 0;
                    else jd = -1;
                }
                else if(cmd[i][0]=='d'){
                    if(jd!=2 && jd!=1) return 0;
                    else jd = 1;
                }
                else{
                    if(jd!=2 && jd!=0) return 0;
                    else jd = 0;
                }
            }
        }
        if((jd==2) && cmd[i][0]!='e') return 0;
    }
    return jd;
}
