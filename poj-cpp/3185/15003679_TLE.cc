#include <stdio.h>

int bowl = 0, vst[1<<20];

int flip(int s, int n)
{
        if(n>0) s ^= 1<<n-1;
        s ^= 1<<n;
        if(n<19) s ^= 1<<n+1;
        return s;
}

int ans = 25;
void dfs(int s, int n, int v)
{
        if(!s) {
                if(n < ans) ans = n;
        } else {
                for(int i=0; i<20; i++) {
                        if(s & 1<<i) {
                                if(i>0 && !vst[v | 1<<i-1]) {
                                        vst[v | 1<<i-1] = 1;
                                        dfs(flip(s, i-1), n+1, v | 1<<i-1);
                                }
                                if(!vst[v | 1<<i]) {
                                        vst[v | 1<<i] = 1;
                                        dfs(flip(s, i), n+1, v | 1<<i);
                                }
                                if(i<19 && !vst[v | 1<<i+1]) {
                                        vst[v | 1<<i+1] = 1;
                                        dfs(flip(s, i+1), n+1, v | 1<<i+1);
                                }
                        }
                }
        }
}

int main()
{
        int s;
        for(int i=0; i<20; i++) {
                scanf("%d", &s);
                bowl = bowl*2 + s;
        }
        dfs(bowl, 0, 0);
        printf("%d\n", ans);

        return 0;
}
