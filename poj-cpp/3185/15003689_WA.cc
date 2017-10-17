#include <stdio.h>

int bowl[21];

void flip(int n, int *arr)
{
        if(n-1>=0) arr[n-1] ^= 1;
        arr[n] ^= 1;
        if(n+1<20) arr[n+1] ^= 1;
}

int tmp[21];
int judge(int s)
{
        for(int i=0; i<20; i++)
                tmp[i] = bowl[i];
        for(int i=0; i<20; i++) {
                if(s & 1<<i)
                        flip(i, tmp);
        }
        for(int i=0; i<20; i++)
                if(tmp[i]==1) return 0;
        return 1;
}

int main()
{
        for(int i=0; i<20; i++)
                scanf("%d", &bowl[i]);
        int ans = 25;
        int im = 0;
        if(!bowl[0] && !bowl[1]) im |= 1;
        if(!bowl[18] && !bowl[19]) im |= 1<<19;
        for(int i=1; i<19; i++) {
                if(!bowl[i-1] && !bowl[i] && !bowl[i+1])
                        im |= 1<< i;
        }
        for(int s=0; s<1<<20; s++) {
                if(s & im) continue;
                if(judge(s)) {
                        int cnt = 0;
                        for(int i=0; i<20; i++)
                                if(s & 1<<i) cnt++;
                        if(cnt < ans) ans = cnt;
                }
        }
        printf("%d\n", ans);

        return 0;
}
