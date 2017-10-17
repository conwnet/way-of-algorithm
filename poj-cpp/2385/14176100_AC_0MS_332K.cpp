#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[1100][35], T, W, apple[1100];

int dfs(int t, int w);

int main()
{
        int i, j, ans;

        scanf("%d%d", &T, &W);
        for(i=1; i<=T; i++) scanf("%d", &apple[i]);
        apple[0] = 2;
        memset(arr, -1, sizeof(arr));
        printf("%d\n", dfs(0, 0));

        return 0;
}

int dfs(int t, int w)
{
        if(arr[t][w]!=-1) return arr[t][w];
        int res = (apple[t]-1==(w&1)), a, b;
        if(t==T) return arr[t][w]=res;
        if(w==W) return arr[t][w]=res+dfs(t+1, w);
        else {
               // if(t==3) printf("%d %d\n", dfs(t+1, w), dfs(t+1, w+1));
                return arr[t][w]=res+max(dfs(t+1, w), dfs(t+1, w+1));
        }
}
