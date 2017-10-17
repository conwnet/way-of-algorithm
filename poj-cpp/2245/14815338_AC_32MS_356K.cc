#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, arr[14], path[6];

void dfs(int s, int n)
{
        if(n==6) {
                printf("%d", path[0]);
                for(int i=1; i<6; i++)
                        printf(" %d", path[i]);
                printf("\n");
                return ;
        }
        for(int i=s; i<N; i++) {
                path[n] = arr[i];
                dfs(i+1, n+1);
        }
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        scanf("%d", &arr[i]);
                dfs(0, 0);
                printf("\n");
        }

        return 0;
}
