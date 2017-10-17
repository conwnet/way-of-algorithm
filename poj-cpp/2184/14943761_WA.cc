#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxv = 100010;
const int mid = 150000;
int dp[2][maxv*3], N, cow[2][128];
const int INF = 0xbfbfbfbf;

int main()
{
        int p;
        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%d%d", &cow[0][i], &cow[1][i]);
        }
        memset(dp, 0xbf, sizeof(dp)); dp[0][mid] = 0;
        for(int i=1; i<=N; i++) {
                if(i&1) p = 1; else p = 0;
                for(int j=-maxv; j<maxv; j++) {
                        //if(dp[p^1][j+mid]==-INF && dp[p^1][j-cow[0][i]+mid]==INF)
                        dp[p][j+mid] = max(dp[p^1][j+mid],
                                dp[p^1][j-cow[0][i]+mid]+cow[0][i]+cow[1][i]);
                }

        }
        if(N&1) p = 1; else p = 0;
        int ans = 0;
        for(int i=0; i<maxv*3; i++) {
                //if(dp[p][i]) printf("%d %d\n", i-mid, dp[p][i]);
                if(dp[p][i]+mid>=i) ans = max(ans, dp[p][i]);
        }
        printf("%d\n", ans);

        return 0;
}

/**<

5
-5  7 2
 8 -6 2
 6 -3 3
 2  1 3
-8 -5 -13

 */


/**
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 128;
struct P {
        int a, b, c;
        P(int a, int b, int c):
                a(a), b(b), c(c) {}
        P() {}
        bool operator < (const P &B) const {
                if(a != B.a) return a < B.a;
                if(b != B.b) return a < B.b;
                if(c != B.c) return c < B.c;
        }
};

int N, arr[2][maxn];
map<P, int> dp;
int dfs(int n, int l, int r)
{
        if(dp[P(n, l, r)]>0) return dp[P(n, l, r)];
        if(n==N) {
                return 0;
        } else {
                int a = dfs(n+1, l+arr[0][n], r+arr[1][n]) + arr[0][n]+arr[1][n];
                int b = dfs(n+1, l, r);
                return dp[P(n, l, r)] = max(a, b);
        }
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d%d", &arr[0][i], &arr[1][i]);
        map<P, int>::iterator it;
        dfs(0, 0, 0)
        int ans = 0;
        for(it=dp.begin(); it!=dp.end(); i++) {
                if()
        }
        printf("%d\n", );

        return 0;
}
*/
