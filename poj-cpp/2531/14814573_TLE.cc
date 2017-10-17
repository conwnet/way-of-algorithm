#include <stdio.h>

int N, f[25][25];

int calc(int s)
{
        int cnt = 0;
        for(int i=0; i<N; i++) {
                if(s & (1<<i)) continue;
                for(int j=0; j<N; j++) {
                        if(s & (1<<j))
                                cnt += f[i][j];
                }
        }
        return cnt;
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++)
                        scanf("%d", &f[i][j]);
        }
        int ans = 0;
        for(int i=0; i<1<<N; i++) {
                int t = calc(i);
                if(t > ans) ans = t;
        }
        printf("%d\n", ans);

        return 0;
}
