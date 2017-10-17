#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 100005;
int dp[maxn][100];
int bit[maxn];
int N, M;

inline int lowbit(int x)
{
        return x&-x;
}

void Add(int pos, int n)
{
        while(pos<=N) {
                bit[pos] += n;
                pos += lowbit(pos);
        }
}

int Sum(int pos)
{
        int sum = 0;
        while(pos>0) {
                sum += bit[pos];
                pos -= lowbit(pos);
        }
        return sum;
}

int dfs(int num, int n)
{
        if(dp[num][n]!=-1)
                return dp[num][n];
        if(n==0) {
                return Sum(N)-Sum(num-1);
        }
        int ans = INF;
        for(int i=num; i<=N-n+1; i++) {
                int tmp = Sum(i-1)-Sum(num-1);
                tmp = max(tmp, dfs(i, n-1));
                ans = min(ans, tmp);
        }
        return dp[num][n] = ans;
}

int main()
{
        int t;

        memset(dp, -1, sizeof(dp));
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) {
                scanf("%d", &t);
                Add(i, t);
        }
        printf("%d\n", dfs(0, M-1));

        return 0;
}





