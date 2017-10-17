#include <stdio.h>
#include <string.h>

int main()
{
        int L, T, O, l, r, c, i, bod[100100], arrT[40], cnt;
        char cmd[5];

        scanf("%d%d%d", &L, &T, &O);
        for(i=0; i<100100; i++) bod[i] = 1;
        while(O--){
                scanf("%s", cmd);
                if(cmd[0]=='C'){
                        scanf("%d%d%d", &l, &r, &c);
                        if(l>r) l^=r^=l^=r;
                        for(i=l; i<=r; i++){
                                bod[i] = c;
                        }
                }else{
                        scanf("%d%d", &l, &r);
                        memset(arrT, 0, 160);
                        for(i=l; i<=r; i++){
                                arrT[bod[i]] = 1;
                        }
                        for(i=1, cnt=0; i<=30; i++){
                                if(arrT[i]) cnt++;
                        }
                        printf("%d\n", cnt);
                }
        }

        return 0;
}
