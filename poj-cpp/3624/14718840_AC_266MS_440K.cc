#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 13000;

int V, N, f[maxn], v[maxn], w[maxn];

int main()
{
        int i, j;

        memset(f, 0, sizeof(f));
        scanf("%d%d", &N, &V);
        for(i=0; i<N; i++){
                scanf("%d%d", &v[i], &w[i]);
        }
        for(i=0; i<N; i++){
                for(j=V; j>=v[i]; j--){
                        f[j] = max(f[j], f[j-v[i]]+w[i]);
                }
        }
        printf("%d\n", f[V]);

        return 0;
}