
#include <stdio.h>

int bowl;

void flip(int &s, int n)
{
        if(n>0) s ^= 1<<n-1;
        s ^= 1<<n;
        if(n<19) s ^= 1<<n+1;
}

int judge(int s)
{
        int b = bowl;
        for(int i=0; i<20; i++) {
                if(s & 1<<i)
                        flip(b, i);
        }
        return !b;
}

int ans = 25;
int dfs(int l, int s, int d)
{
        if(d==0) {
                if(judge(s)) {
                        int cnt = 0;
                        for(int i=0; i<20; i++)
                                if(s & 1<<i) cnt++;
                        if(cnt < ans) ans = cnt;
                        return 1;
                }
                return 0;
        }
        if(l>19) return 0;
        if(dfs(l+1, s | 1<<l, d-1)) return 1;;
        if(dfs(l+1, s, d)) return 1;
}

int main()
{
        int a;
        for(int i=0; i<20; i++) {
                scanf("%d", &a);
                bowl = bowl*2 + a;
        }
        for(int i=0; i<=20; i++)
                if(dfs(0, 0, i)) break;
        printf("%d\n", ans);

        return 0;
}