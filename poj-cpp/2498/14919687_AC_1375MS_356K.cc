#include <stdio.h>
#include <string.h>

int num[10], H;

int cal()
{
        int s = 0;
        for(int i=0; i<H; i++) {
                int m = i%3;
                if(0==m) s += num[H-i-1]*9;
                else if(1==m) s += num[H-i-1]*3;
                else s += num[H-i-1]*7;
        }
        return s;
}

int main()
{
        int T, ch, f;
        scanf("%d", &T);
        getchar();
        for(int nC=1; nC<=T; nC++) {
                H = 0;
                while(ch=getchar()) {
                        if('\n'==ch) break;
                        if('?'==ch) { f = H; num[H++] = 0; }
                        else num[H++] = ch-'0';
                }
                for(int i=0; i<=9; i++) {
                        num[f] = i;
                        if(0==cal()%10) break;
                }
                printf("Scenario #%d:\n", nC);
                for(int i=0; i<H; i++) {
                        printf("%d", num[i]);
                }
                printf("\n\n");
        }

        return 0;
}
