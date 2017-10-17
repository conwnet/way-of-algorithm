#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
int dp[201][21][805];
int path[201][21][805];
int s1[201], s2[201];
int N, M, sum, ans;
vector<int> ansp;

int main()
{
        int nCase = 0, a, b;

        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                for(int i=1; i<=N; i++) {
                        scanf("%d%d", &a, &b);
                        s1[i] = a-b;
                        s2[i] = a+b;
                }
                memset(dp, 0xbf, sizeof(dp));
                memset(path, -1, sizeof(path));
                for(int i=0; i<=N; i++) dp[i][0][400] = 0;
                for(int i=1; i<=N; i++) {
                        for(int j=1; j<=M; j++) {
                                for(int k=-400; k<=400; k++) {
                                        if(k+400-s1[i] >= 0 && k+400-s1[i]<=802) {
                                                if(dp[i-1][j][k+400] >= dp[i-1][j-1][k+400-s1[i]] + s2[i]) {
                                                        dp[i][j][k+400] = dp[i-1][j][k+400];
                                                        path[i][j][k+400] = 0;
                                                }
                                                else {
                                                        dp[i][j][k+400] = dp[i-1][j-1][k+400-s1[i]] + s2[i];
                                                        path[i][j][k+400] = 1;
                                                }
                                        }
                                }
                        }
                }
                ans = INF;
                for(int i=0; i<=800; i++) {
                        if(dp[N][M][i]>=0) {
                                if(abs(i-400) < abs(ans-400)) {
                                        ans = i;
                                        sum = dp[N][M][i];
                                } else if(abs(i-400) == abs(ans-400) && dp[N][M][i] > sum) {
                                        ans = i;
                                        sum = dp[N][M][i];
                                }
                        }
                }
                int lc = (ans-400 + dp[N][M][ans]) >> 1;
                int rc = dp[N][M][ans] - lc;
                printf("Jury #%d\n", ++nCase);
                printf("Best jury has value %d for prosecution and value %d for defence: \n", lc, rc);
                int j = M, k = ans;
                ansp.clear();
                for(int i=N; i>0; i--) {
                        if(path[i][j][k]>0) {
                                ansp.push_back(i);
                                j--;
                                k -= s1[i];
                        }
                }
                sort(ansp.begin(), ansp.end());
                for(int i=0; i<ansp.size(); i++)
                        printf(" %d", ansp[i]);
                printf("\n");
        }

        return 0;
}

/**

dp[i+1][j+1][k+s1[i]] = dp[i][j][k]

-1 3
-1 5
 3 5
 4 8

0 0 400   0
0 1

for(int i=0; i<M; i++) {
                        for(int j=-400; j<400; j++) {
                                if(dp[i][j+400]>=0)
                                for(int k=1; k<=N; k++) {
                                        int f, t = i, tt = j+400;
                                        for(f=path[t][tt+400]; f!=-1 && t>=0; f=path[t-1][tt+400-s1[f]], t--, tt=tt+400-s1[f]) {
                                                if(f==k) break;
                                        }
                                        if(f!=-1) continue;
                                        if(j+400+s1[k]>=0 && dp[i][j+400] + s2[k] > dp[i+1][j+400+s1[k]]) {
                                                dp[i+1][j+400+s1[k]] = dp[i][j+400] + s2[k];
                                                path[i+1][j+400+s1[k]] = k;
                                        }
                                }
                        }
                }
ans = INF;
                for(int i=0; i<800; i++) {
                        if(dp[M][i]>=0) {
                                if(abs(i-400)<abs(ans-400)) {
                                        ans = i;
                                        sum = dp[M][i];
                                }
                                else if(abs(i-400)==abs(ans-400) && dp[M][i]>sum)
                                        sum = dp[M][i];
                        }
                }
                int lc = (ans-400+dp[M][ans]) / 2;
                int rc = dp[M][ans] - lc;

dp[3][2][2] = 10;
dp[3][2][]
*/

/**
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct P {
        int a, b, r;
};
P arr[201];
const int INF = 0x3f3f3f3f;
int dp[201][21][805];
int N, M, ans, ju[21], pr[21];
int path[201], lc, rc;
vector<int> ansp;

int cmp(P A, P B)
{
        return A.a + A.b > B.a + B.b;
}

dp[num][n][dif] = max(dp[num-1][n][dif], dp[num-1][n-1][dif-s[1]]+s[2]);

int dfs(int num, int n, int dif)
{
        if(dp[num][n][dif] >= 0)
                return dp[num][n][dif];
        if(num==N && n==M) {
                if(abs(dif)<=ans) {
                        int tl = 0;
                        int tr = 0;
                        for(int i=0; i<N; i++) {
                                if(path[i]==1) {
                                        tl += arr[i].a;
                                        tr += arr[i].b;
                                }
                        }
                        if(abs(dif)<ans || tl+tr > lc+rc) {
                                lc = tl;
                                rc = tr;
                                ans = abs(dif);
                                ansp.clear();
                                for(int i=0; i<N; i++) {
                                        if(path[i]==1) {
                                                ansp.push_back(arr[i].r+1);
                                        }
                                }
                        }
                }
                return dp[num][n][dif] = abs(dif);
        }
        int a = INF;
        int b = INF;
        if(n<M) {
                path[num] = 1;
                a = dfs(num+1, n+1, dif+arr[num].a-arr[num].b);
        }
        if(M-n < N-num) {
                path[num] = 0;
                b = dfs(num+1, n, dif);
        }
        return dp[num][n][dif] = min(a, b);
}

int main()
{
        int nCase = 0;

        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                for(int i=0; i<N; i++) {
                        scanf("%d%d", &arr[i].a, &arr[i].b);
                        arr[i].r = i;
                }
                sort(arr, arr+N, cmp);
                memset(dp, -1, sizeof(dp));
                memset(path, 0, sizeof(path));
                lc = rc = -1;
                ans = INF;
                dfs(0, 0, 0);
                printf("Jury #%d\n", ++nCase);
                printf("Best jury has value %d for prosecution and value %d for defence:\n", lc, rc);
                sort(ansp.begin(), ansp.end());
                for(int i=0; i<ansp.size(); i++)
                        printf(" %d", ansp[i]);
                printf("\n");
        }

        return 0;
}
*/




