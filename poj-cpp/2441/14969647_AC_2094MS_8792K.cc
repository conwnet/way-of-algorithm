#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][1<<20], N, M;
const int MOD = 10000000;
vector<int> P[21];

int main()
{
        int n, a;
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) {
                scanf("%d", &n);
                for(int j=0; j<n; j++) {
                        scanf("%d", &a);
                        P[i].push_back(a-1);
                }
        }
        for(int i=0; i<1<<M; i++) dp[0][i] = 1;
        for(int i=1; i<=N; i++) {
                int p = i&1;
                for(int s=0; s<1<<M; s++) {
                        int cc = 0;
                        for(int j=0; j<M; j++)
                                if(s & 1<<j) cc++;
                        if(cc!=N-i) continue;
                        int cnt = 0;
                        for(int j=0; j<P[i].size(); j++) {
                                if(s & 1<<P[i][j]) continue;
                                cnt = (cnt + dp[p^1][s | (1<<P[i][j])]) % MOD;
                        }
                        dp[p][s] = cnt;
                }
        }
        printf("%d\n", dp[N&1][0]);

        return 0;
}

/**
int dp[20][1<<20], N, M;
const int MOD = 10000000;
vector<int> P[21];

int dfs(int n, int s)
{
        if(dp[n][s]!=-1) return dp[n][s];
        if(n==N-1) {
                int ret = 0;
                for(int i=0; i<P[n].size(); i++)
                        if(0 == (s & 1<<P[n][i])) ret++;
                return dp[n][s] = ret;
        }
        int a = 0;
        for(int i=0; i<P[n].size(); i++) {
                if(s & 1<<P[n][i]) continue;
                a = (a + dfs(n+1, s | 1<<P[n][i])) % MOD;
        }
        return dp[n][s] = a;
}

int main()
{
        int n, a;
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                scanf("%d", &n);
                for(int j=0; j<n; j++) {
                        scanf("%d", &a);
                        P[i].push_back(a-1);
                }
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, 0));

        return 0;
}
*/


