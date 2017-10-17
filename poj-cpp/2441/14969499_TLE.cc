#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int dp[20][1<<20], N, M;
const int MOD = 10000000;
vector<int> P[21];

int dfs(int n, int s)
{
        if(dp[n][s]) return dp[n][s];
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
        printf("%d\n", dfs(0, 0));

        return 0;
}
