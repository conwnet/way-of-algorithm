#include <stdio.h>
#include <string.h>

int maps[16], tmp[16];

int judge()
{
        int i;
        for(i=1; i<16; i++)
                if(tmp[i]!=tmp[i-1]) return 0;
        return 1;
}

int change(int n)
{
        int i, j;
        int row = n/4;
        int col = n%4;
        for(i=row*4; i<row*4+4; i++) tmp[i] ^= 1;
        for(i=0; i<4; i++) tmp[i*4+col] ^= 1;
        tmp[n] ^= 1;
}

int main()
{
        int i, j, ans, t, cnt;
        char ch;

        for(i=0; i<4; i++) {
                for(j=0; j<4; j++) {
                        scanf("%c", &ch);
                        if(ch=='b') maps[i*4+j] = 1;
                        else maps[i*4+j] = 0;
                }
                getchar();
        }
        ans = 99;
        for(i=0; i<(1<<16); i++) {
                memcpy(tmp, maps, sizeof(maps));
                for(j=0; j<16; j++)
                        if((1<<j)&i) change(j);
                if(judge()) {
                        t = 0;
                        for(j=0; j<16; j++)
                                if((1<<j)&i) t++;
                        if(t<ans) { ans = t; cnt = i; }
                }
        }
        printf("%d\n", ans);

        return 0;
}
