#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 5005;
const int maxe = 30000;
int fir[maxn], to[maxe], next[maxe], ec;

void add_edge(int u, int v)
{
        to[ec] = v;
        next[ec] = fir[u]; fir[u] = ec++;
        to[ec] = u;
        next[ec] = fir[v]; fir[v] = ec++;
}

int low[maxn], ts;
void dfs(int v, int pa)
{
        low[v] = ++ts;
        for(int i=fir[v]; i!=-1; i=next[i]) {
                if(to[i]==pa) continue;
                if(!low[to[i]])
                        dfs(to[i], v);
                if(low[to[i]] < low[v])
                        low[v] = low[to[i]];
        }
}

int F, R, deg[maxn];
int main()
{
        int u, v;
        memset(fir, -1, sizeof(fir)); ec = 0;
        scanf("%d%d", &F, &R);
        while(R--) {
                scanf("%d%d", &u, &v);
                add_edge(u, v);
                add_edge(v, u);
        }
        dfs(1, -1);
        memset(deg, 0, sizeof(deg));
        for(int i=1; i<=F; i++) {
                for(int j=fir[i]; j!=-1; j=next[j]) {
                        if(low[i]==low[to[j]]) continue;
                        deg[low[to[j]]]++;
                }
        }
        int ans = 0;
        for(int i=1; i<=F; i++)
                if(deg[i]>>1==1) ans++;
        printf("%d\n", ans+1>>1);

        return 0;
}

