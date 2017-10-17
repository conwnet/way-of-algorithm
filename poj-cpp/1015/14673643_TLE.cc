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

int dfs(int num, int n, int dif)
{
        //if(dp[num][n][dif] >= 0)\
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
                printf("Best jury has value %d for prosecution and value %d for defence: \n", lc, rc);
                sort(ansp.begin(), ansp.end());
                for(int i=0; i<ansp.size(); i++)
                        printf(" %d", ansp[i]);
                printf("\n");
        }

        return 0;
}
