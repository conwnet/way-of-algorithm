#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T, W, apple[1100];

int dfs(int t, int w);

int main()
{
        int i, j, ans;

        scanf("%d%d", &T, &W);
        for(i=1; i<=T; i++) scanf("%d", &apple[i]);
        apple[0] = 2;
        printf("%d\n", dfs(0, 0));

        return 0;
}

int dfs(int t, int w)
{
        int res = (apple[t]-1==(w&1)), a, b;
        if(t==T) return res;
        if(w==W) return res+dfs(t+1, w);
        else {
               // if(t==3) printf("%d %d\n", dfs(t+1, w), dfs(t+1, w+1));
                return res+max(dfs(t+1, w), dfs(t+1, w+1));
        }
}
