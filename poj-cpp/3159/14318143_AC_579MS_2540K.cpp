
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int M, N, u[150010], v[150010], w[150010];
int d[30010], fir[30010], nxt[30010];

int dijkstra();

int main()
{
        memset(fir, -1, sizeof(fir));
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++) {
                scanf("%d%d%d", &u[i], &v[i], &w[i]);
                nxt[i] = fir[u[i]];
                fir[u[i]] = i;
        }
        printf("%d\n", dijkstra());
        return 0;
}

typedef pair<int, int> P;

int dijkstra()
{
        priority_queue<P, vector<P>, greater<P> > pq;
        for(int i=0; i<=N; i++) d[i] = 99999999;
        d[1] = 0;
        pq.push(P(0, 1));
        while(!pq.empty()) {
                P t = pq.top(); pq.pop();
                int vv = t.second;
                if(d[vv]<t.first) continue;
                for(int p=fir[vv]; p!=-1; p=nxt[p]) {
                        if(d[vv]+w[p] < d[v[p]]) {
                                d[v[p]] = d[vv] + w[p];
                                pq.push(P(d[v[p]], v[p]));
                        }
                }
        }
        return d[N];
}
