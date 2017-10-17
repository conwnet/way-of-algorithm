#include <stdio.h>
#include <string.h>

#define X 201
#define Y 201

int stepx[X];
int stepy[Y];

int main(){
    int x, y, m, n, L, i, step, flag;
    while(~scanf("%d%d%d%d%d", &x, &y, &m, &n, &L)){
        memset(stepx, -1, X*4);
        memset(stepy, -1, Y*4);
        flag = 0;
        for(i=x, step=0; stepx[i]==-1; i+=m){
            if(i>L) i %= L;
            stepx[i] = step++;
        }
        for(i=y, step=0; stepy[i]==-1; i+=n){
            if(i>L) i %= L;
            stepy[i] = step++;
        }
        for(i=1; i<=L; i++){
            if(stepx[i]==stepy[i] && stepx[i]!=-1){
                flag = stepx[i];
                break;
            }
        }
        if(flag) printf("%d\n", flag);
        else printf("Impossible\n");
    }

    return 0;
}
