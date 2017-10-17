#include <stdio.h>

int bowl[21];

void flip(int n)
{
        bowl[n-1] ^= 1;
        bowl[n] ^= 1;
        bowl[n+1] ^= 1;
}

int main()
{
        for(int i=0; i<20; i++)
                scanf("%d", &bowl[i]);
        int cnt = 0;
        for(int i=0; i<20; i++) {
                if(bowl[i]==1) {
                        flip(i+1);
                        cnt++;
                }
        }
        printf("%d\n", cnt);

        return 0;
}
