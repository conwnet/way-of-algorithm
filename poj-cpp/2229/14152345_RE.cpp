#include <stdio.h>

int cnt;

int dfs(int s, int N);

int main()
{
        int N, i;

        scanf("%d", &N);
        cnt = 0;
        dfs(0, N);
        printf("%d\n", cnt);

        return 0;
}

int dfs(int s, int N)
{
        int i, t;

        if(N==0) cnt++;
        else
                for(i=s; i<N; i++) {
                        t = 1<<i;
                        if(N-t>=0) dfs(i, N-t);
                        else break;
                }
        return 0;
}
