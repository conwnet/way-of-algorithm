#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Point {
        int x, y;
} dot[20];
const int INF = 0x3f3f3f3f;
int dp[1<<15], N;

int cal_area(int s)
{
        int x1, x2, y1, y2;
        x1 = y1 = INF;
        x2 = y2 = -INF;
        for(int i=0; i<N; i++) {
                if(!(s & 1<<i)) continue;
                if(dot[i].x < x1) x1 = dot[i].x;
                if(dot[i].y < y1) y1 = dot[i].y;
                if(dot[i].x > x2) x2 = dot[i].x;
                if(dot[i].x > y2) y2 = dot[i].y;
        }
        return (x2-x1) * (y2-y1);
}

int Count(int s)
{
        int ret = 0;
        for(int i=0; i<N; i++)
                if(s & 1<<i) ret++;
        return ret;
}

int build_sta(int s, int t, int n)
{
        int p = 0, ret = 0;
        for(int i=0; i<n; i++) {
                while(!(s & 1<<p)) p++;
                if(t & 1<<i) continue;
                ret += 1<<p;
        }
        return ret;
}

int dfs(int s)
{
        if(dp[s]) return dp[s];
        int ret = cal_area(s);
        int n = Count(s);
        for(int i=0; i<1<<n; i++) {
                int s0 = build_sta(s, i, n);
                int n0 = Count(s0);
                if(n0<2 || n-n0<2) continue;
                ret = min(ret, dfs(s0)+dfs(s-s0));
        }
        return dp[s] = ret;
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        scanf("%d%d", &dot[i].x, &dot[i].y);
                memset(dp, 0, sizeof(dp));
                printf("%d\n", dfs((1<<N)-1));
        }

        return 0;
}
