#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M, minv[25], minh[25];
int ans;

int dfs(int r, int h, int n, int v, int s)
{
        int i, j;

        if(n==0) {
                if(v) return 0;
                else {
                        ans = min(s, ans);
                        return 0;
                }
        }
        if(v<=0) return 0;
        for(i=r; i>=n; i--) {
                if(n==M) s = i*i;
                for(j=h; j>=n; j--) {
                        dfs(i-1, j-1, n-1, v-i*i*j, s+i*2*j);
                        ///printf("%d %d %d\n", i, j, s);
                }
        }
        return 0;
}

int main()
{
        int i, j;

        scanf("%d%d", &N, &M);
        minv[1] = minh[1] = 1;
        for(i=1; i<=M; i++) {
                minh[i] = i;
        }
        ans = 1<<30;
        dfs(N, N, M, N, 0);
        printf("%d\n", ans);


        return 0;
}
