#include <stdio.h>
#include <string.h>

const int maxn = 512;
int fir[maxn], to[maxn*maxn], next[maxn*maxn], ec;

void add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
        to[ec] = u; next[ec] = fir[v]; fir[v] = ec++;
}

int match[maxn], vst[maxn];

int dfs(int u)
{
        vst[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i], w = match[v];
                if(w<0 || !vst[w] && dfs(w)) {
                        match[u] = v;
                        match[v] = u;
                        return 1;
                }
        }
        return 0;
}

int main()
{
        int N, n, m, a;
        while(~scanf("%d", &N)) {
                memset(fir, -1, sizeof(fir));
                for(int i=0; i<N; i++) {
                        scanf("%d: (%d)", &n, &m);
                        while(m--) {
                                scanf("%d", &a);
                                add_edge(n, a);
                        }
                }
                int ans = 0;
                memset(match, -1, sizeof(match));
                for(int i=0; i<N; i++) {
                        if(match[i]<0) {
                                memset(vst, 0, sizeof(vst));
                                if(dfs(i)) ans++;
                        }
                }

                printf("%d\n", N-ans);
        }

        return 0;
}
