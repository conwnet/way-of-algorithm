#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){
    int a, b, c;
    int m, n, i, j, sum=0;
    int *que;
    char cmd[20];

    while(scanf("%d%d", &m, &n)){
        que = (int *)malloc(m*4);
        for(i=0; i<m; i++){
            scanf("%d", &que[i]);
        }
        for(i=0; i<=n; i++){
            memset(cmd, 0, 20);
            gets(cmd);
            if(cmd[0]=='Q'){
                sscanf(cmd, "Q %d %d", &a, &b);
                for(j=a-1; j<b; j++){
                    sum += que[j];
                }
                printf("%d\n", sum);
                sum = 0;
            }
            else{
                sscanf(cmd, "C %d %d %d", &a, &b, &c);
                for(j=a-1; j<b; j++){
                    que[j] += c;
                }
            }
        }
        break;
    }
    return 0;
}
