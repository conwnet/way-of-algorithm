#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int cow[maxn], s[maxn][35], a[maxn][35], ra[maxn], N, K;

int cmp(int x, int y)
{
        for(int i=1; i<=K; i++) {
                if(a[x][i]==a[y][i]) continue;
                return a[x][i] < a[y][i];
        }
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=1; i<=N; i++)
                scanf("%d", &cow[i]);
        for(int i=1; i<=N; i++) {
                for(int j=0; j<K; j++) {
                        s[i][j] = s[i-1][j] + !!(cow[i]&1<<j);
                }
        }
        for(int i=1; i<=N; i++) {
                for(int j=1; j<K; j++)
                        a[i][j] = s[i][j]-s[i][0];
                a[i][K] = i;
        }
        for(int i=0; i<=N; i++) ra[i] = i;
        sort(ra+1, ra+N+1, cmp);
        int ans = 0, p = 0;
        for(int i=1; i<=N; i++) {
                int q = ra[i];
                int eq = 1;
                for(int j=1; j<K; j++)
                        if(a[p][j]!=a[q][j]) {
                                p = q;
                                eq = 0;
                                break;
                        }
                ///for(int j=0; j<=K; j++) printf("%d ", a[q][j]); printf("\n");
                if(eq) ans = max(ans, a[q][K]-a[p][K]);
        }
        printf("%d\n", ans);

        return 0;
}
