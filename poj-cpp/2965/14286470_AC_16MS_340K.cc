#include <stdio.h>
#include <string.h>

int maps[16], ans[16];

int change(int n)
{
        int row = n/4;
        int col = n%4;
        int i;
        for(i=row*4; i<row*4+4; i++) ans[i]++;
        for(i=0; i<4; i++) ans[i*4+col]++;
        ans[n]++;
}

int main()
{
        int i, j, cnt;

        for(i=0; i<4; i++) {
                for(j=0; j<4; j++) {
                        if(getchar()=='+') maps[i*4+j] = 1;
                        else maps[i*4+j] = 0;
                }
                getchar();
        }
        memset(ans, 0, sizeof(ans));
        for(i=0; i<16; i++) {
                if(maps[i]) change(i);
        }
        cnt = 0;
        for(i=0; i<16; i++) {
                ans[i] %= 2;
                if(ans[i]>0) cnt++;
        }
        printf("%d\n", cnt);
        for(i=0; i<16; i++) if(ans[i]) printf("%d %d\n", i/4+1, i%4+1);

        return 0;
}
