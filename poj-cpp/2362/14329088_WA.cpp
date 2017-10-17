#include <stdio.h>
#include <string.h>

int w[30], r[30], N, V;

int dfs(int n, int v);

int main()
{
        int T;

        scanf("%d", &T);
        while(T--) {
                memset(r, 0, sizeof(r));
                scanf("%d", &N);
                V = 0;
                for(int i=0; i<N; i++) {
                        scanf("%d", &w[i]);
                        V += w[i];
                }
                if(V%4) printf("no\n");
                else {
                        V /= 4;
                        if(dfs(0, 0) && dfs(0, 0) && dfs(0, 0)) printf("yes\n");
                        else printf("no\n");
                }
        }

        return 0;
}

int dfs(int n, int v)
{
        if(n==N) return 0;
        if(v==V) return 1;
        if(!r[n]) {
                r[n] = 1;
                if(dfs(n+1, v+w[n])) return 1;
                r[n] = 0;
        }
        if(dfs(n+1, v)) return 1;
        return 0;
}
