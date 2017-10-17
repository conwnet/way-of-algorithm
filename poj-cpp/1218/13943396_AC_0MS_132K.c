#include <stdio.h>
#include <string.h>

int main()
{
    int lst[200], cell[200], cnt, n, spc, i, nCase;
    memset(lst, 0, sizeof(lst));
    for(n=5; n<=100; n++){
        memset(cell, 0, sizeof(cell));
        for(spc=1; spc<=n; spc++){
            for(i=spc; i<=n; i+=spc){
                cell[i]++;
            }
        }
        for(i=1, cnt=0; i<=n; i++){
            if(cell[i]%2) cnt++;
        }
        lst[n] = cnt;
    }
    scanf("%d", &nCase);
    while(nCase--){
        scanf("%d", &i);
        printf("%d\n", lst[i]);
    }
    return 0;
}