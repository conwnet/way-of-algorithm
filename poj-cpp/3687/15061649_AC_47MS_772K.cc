#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 210;
int fir, vex[maxn*maxn], next[maxn*maxn], ec, cnt, V, E, outd[maxn], ans[maxn];
vector<int> G[maxn];
priority_queue<int> pq;

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &V, &E);
                memset(outd, 0, sizeof(outd));
                for(int i=1; i<=V; i++) G[i].clear();
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        G[v].push_back(u);
                        outd[u]++;
                }
                for(int i=1; i<=V; i++)
                        if(0==outd[i]) pq.push(i);
                fir = -1;
                ec = cnt = 0;
                while(!pq.empty()) {
                        u = pq.top(); pq.pop(); cnt++;
                        vex[ec] = u; next[ec] = fir; fir = ec++;
                        for(int i=0; i<G[u].size(); i++) {
                                v = G[u][i];
                                outd[v]--;
                                if(0==outd[v]) pq.push(v);
                        }
                }
                if(cnt<V) { printf("-1\n"); continue; }
                for(int i=1, t = fir; i<=V; i++) {
                        ans[vex[t]] = i;
                        t = next[t];
                }
                printf("%d", ans[1]);
                for(int i=2; i<=V; i++)
                        printf(" %d", ans[i]);
                printf("\n");
        }

        return 0;
}