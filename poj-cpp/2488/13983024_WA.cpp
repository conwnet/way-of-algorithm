#include <stdio.h>
#include <string.h>

int mapp[30][30];
char road[1000];
char strr[30][30][300];

int dfs(int h, int w, int a, int b);

int main()
{
        int nCase, h, w, n = 1, l, i, j, cnt=0;

        scanf("%d", &nCase);

        memset(strr, 0, sizeof(strr));
        //dfs(3, 4, 0, 0);
        for(i=1; i<26; i++){
                for(j=1; i*j<=26; j++){
                        road[0] = '\0';
                        dfs(j, i, 0, 0);
                        strcpy(strr[j][i], road);
                }
        }
        while(nCase--){
                scanf("%d%d", &h, &w);
                memset(mapp, 0, sizeof(mapp));
                printf("Scenario #%d:\n", n++);
                if(w==1 && h==1){
                        printf("A1\n");
                        continue;
                }

                if(!strr[h][w][0])printf("impossible\n\n");
                else printf("A1%s\n\n", strr[h][w]);

        }

        return 0;
}

int dfs(int h, int w, int y, int x)
{
        int a, b, l;
        char str[10];

        mapp[y][x] = 1;

        a = y-1;
        b = x-2;
        if(a>=0 && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+1;
        b = x-2;
        if(a<h && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y-2;
        b = x-1;
        if(a>=0 && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }


        a = y+2;
        b = x-1;
        if(a<h && b>=0 && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y-2;
        b = x+1;
        if(a>=0 && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }

        a = y+2;
        b = x+1;
        if(a<h && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }


        a = y-1;
        b = x+2;
        if(a>=0 && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }


        a = y+1;
        b = x+2;
        if(a<h && b<w && !mapp[a][b]){
                sprintf(str, "%c%d", b+'A', a+1);
                strcat(road, str);
                if(dfs(h, w, a, b)) return 1;
                l = strlen(road);
                road[l-2] = '\0';
        }



        mapp[y][x] = 0;
        l = strlen(road);
        if(l/2 == h*w-1) return 1;
        return 0;
}













