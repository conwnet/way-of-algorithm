#include <stdio.h>
#include <math.h>

int main(){
    int r[20], g[20], b[20], tr, tg, tb, i, flag;

    for(i=0; i<16; i++){
        scanf("%d%d%d", &r[i], &g[i], &b[i]);
    }
    while(~scanf("%d%d%d", &tr, &tg, &tb)){
        double mins = 99999999;
        if(tr==-1 && tg==-1 && tb==-1) break;
        for(i=0; i<16; i++){
            double t = sqrt( (tr-r[i])*(tr-r[i]) + (tg-g[i])*(tg-g[i]) + (tb-b[i])*(tb-b[i]) );
            if(t<mins){
                mins = t;
                flag = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", tr, tg, tb, r[flag], g[flag], b[flag]);
    }

    return 0;
}
