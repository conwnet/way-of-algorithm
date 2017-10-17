#include <stdio.h>
#include <string.h>

int N, w[30];

int dfs(int n, int v, int V)
{
        if(n==N) return 0;
        if(v==V) return 1;
        if(dfs(n+1, v, V)) return 1;
        if(dfs(n+1, v+w[n], V)) return 1;
        return 0;
}

/**
int f[210000];

int zo_pack(int n)
{
        for(int i=V; i>=w[i]; i--)
                f[i] = max(f[i], f[i-w[i]]);
}
*/
int main()
{
        int T, sum, faild;

        scanf("%d", &T);
        while(T--) {
                faild = 0;
                scanf("%d", &N);
                sum = 0;
                for(int i=0; i<N; i++) {
                        scanf("%d", &w[i]);
                        sum += w[i];
                }
                if(sum%4) faild = 1;
                else {
                        for(int i=1; i<=3; i++) {
                                if(!dfs(0, 0, sum/4*i)) {
                                        faild = 1;
                                        break;
                                }
                        }
                }
                if(faild) printf("no\n");
                else printf("yes\n");
        }

        return 0;
}
