
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int N, M, minv[25], mins[25];
int ans;

int max_v(int n, int r, int h)
{
        int v = 0;
        for(int i=0; i<n; i++)
                v += (r-i)*(r-i)*(h-i);
        return v;
}

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
        if(max_v(n, r, h)<v) return 0;
        if(s+mins[n-1]>=ans) return 0;
        if(minv[n]>v) return 0;
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
        minv[1] = 1; mins[1] = 3;
        for(i=1; i<=M; i++) {
                minv[i] = minv[i-1] + i*i*i;
                mins[i] = mins[i-1] + i*2*i;
        }
        ans = 1<<30;
        int R = sqrt((N-minv[M-1])/M) + 1;
        int H = (N-minv[M-1])/(M*M);
        if(minv[M]>N) {
                printf("0\n");
                return 0;
        }
        dfs(R, H, M, N, 0);
        if(ans<(1<<30))
                printf("%d\n", ans);
        else printf("0\n");

        return 0;
}

