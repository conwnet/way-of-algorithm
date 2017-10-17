#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M, maps[128][128];

int main()
{
        int u, v;
        scanf("%d%d", &N, &M);
        while(M--) {
                scanf("%d%d", &u, &v);
                maps[u][v] = 1;
        }
        for(int i=1; i<=N; i++) {
                for(int j=1; j<=N; j++) {
                        for(int k=1; k<=N; k++) {
                                maps[j][k] = maps[j][k] || maps[j][i]&maps[i][k];
                        }
                }
        }
        int ans = 0;
        for(int i=1; i<=N; i++) {
                int t = 0;
                for(int j=1; j<=N; j++)
                        t += maps[i][j] + maps[j][i];
                if(t==N-1) ans++;
        }
        printf("%d\n", ans);

        return 0;
}