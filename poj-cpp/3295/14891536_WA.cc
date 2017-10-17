#include <stdio.h>
#include <string.h>

char str[512], dat[512], maps[128];

void cut(int p)
{
        if(p<0) return ;
        if(dat[p]<=1 && dat[p]>=0) {
                cut(p-1);
                return ;
        }
        if('N'==dat[p]) {
                dat[p] = dat[p+1] ^ 1;
                cut(p-1);
                return ;
        }
        if('K'==dat[p]) {
                dat[p] = dat[p+1] & dat[p+2];
                cut(p-1);
                return ;
        }
        if('A'==dat[p]) {
                dat[p] = dat[p+1] | dat[p+2];
                cut(p-1);
                return ;
        }
        if('C'==dat[p]) {
                dat[p] = (!dat[p+1] || dat[p+2]);
                cut(p-1);
                return ;
        }
        if('E'==dat[p]) {
                dat[p] = dat[p+1] == dat[p+2];
                cut(p-1);
                return ;
        }
}

int main()
{
        while(scanf("%s", str)) {
                if('0'==str[0]) break;
                int len = strlen(str);
                int faild = 0;
                for(int i=0; i<1<<5; i++) {
                        maps['p'] = !(i & 1<<0);
                        maps['q'] = !(i & 1<<1);
                        maps['r'] = !(i & 1<<2);
                        maps['s'] = !(i & 1<<3);
                        maps['t'] = !(i & 1<<4);
                        memcpy(dat, str, sizeof(str));
                        for(int j=0; j<len; j++) {
                                if('K'!=dat[j] && 'A'!=dat[j] && 'N'!=dat[j] &&
                                   'C'!=dat[j] && 'E'!=dat[j])
                                        dat[j] = maps[dat[j]];
                        }
                        ///printf("%c %d %c %d\n", dat[0], dat[1], dat[2], dat[3]);
                        cut(len-1);
                        if(!dat[0]) { faild = 1; break; }
                }
                if(faild) printf("not\n");
                else printf("tautology\n");
        }

        return 0;
}
