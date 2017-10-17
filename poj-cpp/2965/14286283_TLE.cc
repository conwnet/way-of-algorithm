#include <stdio.h>
#include <string.h>

int maps[16], tmp[16];

int judge()
{
        for(int i=0; i<16; i++)
                if(tmp[i]) return 0;
        return 1;
}

int change(int n)
{
        int row = n/4;
        for(int i=row*4; i<row*4+4; i++) tmp[i] ^= 1;
        int col = n%4;
        for(int i=0; i<4; i++) tmp[i*4+col] ^= 1;
        tmp[n] ^= 1;
}

int main()
{
        int i, j, ans, t, cnt;
        char ch;

        for(i=0; i<4; i++) {
                for(j=0; j<4; j++) {
                        scanf("%c", &ch);
                        if(ch=='+') maps[i*4+j] = 1;
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
        for(j=0; j<16; j++)
                if((1<<j)&cnt) printf("%d %d\n", j/4+1, j%4+1);

        return 0;
}
