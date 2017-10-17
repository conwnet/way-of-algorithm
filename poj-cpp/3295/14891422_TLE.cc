#include <stdio.h>
#include <string.h>

char str[512], dat[512];
int next[512], maps[10], op[128];
int len;

/**
int judge() {
        memcpy(dat, str, sizeof(str));
        for(int i=0; i<len; i++)
                next[i] = i+1;
        for(int i=1; i!=-1; i=next[i]) {
                if('N'==str[i]) {
                        int r = next[i];
                        dat[i] = dat[str[r]]^1;
                        next[i] = next[r];
                }
        }
}
*/

void judge(int p) {
        if(-1==p || -1==next[p]) return ;
        char ch = dat[p];
        int p1, p2;
        p1 = next[p];
        p2 = next[p1];
        if(ch=='p' || ch=='q' || ch=='r' || ch=='s' || ch=='t') {
                judge(p1);
        } else if(('K'==ch || 'A'==ch || 'C'==ch || 'E'==ch) &&
                dat[p2]<=1 && dat[p2]>=0) {
                if('K'==ch) dat[p] = dat[p1] & dat[p2];
                else if('A'==ch) dat[p] = dat[p1] | dat[p2];
                else if('C'==ch) dat[p] = (!dat[p1] || dat[p2]);
                else if('E'==ch) dat[p] = dat[p1] == dat[p2];
                next[p] = next[p2];
                judge(next[p]);
        } else if('N'==ch) {
                dat[p] = dat[p1]^1;
                next[p] = next[p1];
                judge(next[p]);
        } else {
                //printf("test");
                judge(next[p1]);
                judge(p);
        }
}

int main()
{
        while(scanf("%s", str+1)) {
                if('0'==str[1]) break;
                memset(next, -1, sizeof(next));
                len = strlen(str+1);
                for(int i=1; i<=len; i++) {
                        if('p'==str[i]) str[i] = 1;
                        else if('q'==str[i]) str[i] = 2;
                        else if('r'==str[i]) str[i] = 3;
                        else if('s'==str[i]) str[i] = 4;
                        else if('t'==str[i]) str[i] = 5;
                }
                int faild = 0;
                for(int i=0; i<1<<5; i++) {
                        for(int j=0; j<5; j++) {
                                if(i & 1<<j) maps[j+1] = 1;
                                else maps[j+1] = 0;
                        }
                        memset(next, -1, sizeof(next));
                        memcpy(dat, str, sizeof(str));
                        for(int i=1; i<=len; i++) {
                                int ch = str[i];
                                if('K'==ch || 'A'==ch || 'C'==ch || 'E'==ch || 'N'==ch)
                                        continue;
                                else dat[i] = maps[dat[i]];
                        }
                        for(int i=0; i<len; i++)
                                next[i] = i+1;
                        judge(1);
                        if(!dat[1]) { faild = 1; break; }
                }
                if(faild) printf("not\n");
                else printf("tautology\n");
        }

        return 0;
}
