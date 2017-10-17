
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

int ans = 25;
int dfs(int l, int s, int d)
{
        if(l>19) return 0;
        if(d==0) {
                if(judge(s)) {
                        int cnt = 0;
                        for(int i=0; i<20; i++)
                                if(s & 1<<i) cnt++;
                        if(cnt < ans) ans = cnt;
                        return 1;
                }
        }
        if(dfs(l+1, s | 1<<l, d-1)) return 1;;
        if(dfs(l+1, s, d)) return 1;
}

int main()
{
        for(int i=0; i<20; i++)
                scanf("%d", &bowl[i]);
        for(int i=0; i<=20; i++)
                if(dfs(0, 0, i)) break;
        printf("%d\n", ans);

        return 0;
}