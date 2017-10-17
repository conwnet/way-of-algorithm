#include <stdio.h>
#include <string.h>

int N, M, K, maps[40][40];

int dfs(int r, int c, int s)
{
        if(r==N) return 1;
        if(c==M) return dfs(r+1, 0, s);
        if(maps[r][c]) return dfs(r, c+1, s);
        if(s & 1<<c) return dfs(r, c+1, s-(1<<c));
        if(c+1<M && !(s&1<<c+1) && maps[r][c+1]==0) {
                if(dfs(r, c+2, s)) return 1;
        }
        if(r+1<N && maps[r+1][c]==0) {
                if(dfs(r, c+1, s|1<<c)) return 1;
        }
        return 0;
}

int main()
{
        int r, c;
        scanf("%d%d%d", &N, &M, &K);
        while(K--) {
                scanf("%d%d", &r, &c);
                maps[r-1][c-1] = 1;
        }
        if(dfs(0, 0, 0)) printf("YES\n");
        else printf("NO\n");

        return 0;
}

/**
4 4 3
1 4
2 1
4 2
*/
