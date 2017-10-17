#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

struct Edge {
        int t, c, next;
        Edge(int t, int c):
                t(t), c(c) {}
        Edge() {}
};

int fir[50005], next[150005], M;
Edge edge[150005];
int inq[50005], dis[50005];

void add_edge(int s, int t, int c)
{
        edge[M].t = t;
        edge[M].c = c;
        edge[M].next = fir[s];
        fir[s] = M++;
}

int spfa(int s, int t)
{
        queue<int> que;

        memset(inq, 0, sizeof(inq));
        memset(dis, 0xbf, sizeof(dis));
        dis[s] = 0;
        que.push(s);
        inq[s] = 1;
        while(!que.empty()) {
                int tmp = que.front();
                que.pop();
                inq[tmp] = 0;
                for(int i=fir[tmp]; i!=-1; i=edge[i].next) {
                        if(edge[i].c+dis[tmp] > dis[edge[i].t]) {
                                dis[edge[i].t] = edge[i].c+dis[tmp];
                                if(!inq[edge[i].t])
                                        que.push(edge[i].t);
                                        inq[edge[i].t] = 1;
                        }
                }

        }
        return dis[t];
}

int main()
{
        int mins, maxs, u, v, w, N;

        scanf("%d", &N);
        mins = INF; maxs = -INF;
        memset(fir, -1, sizeof(fir));
        M = 0;
        while(N--) {
                scanf("%d%d", &u, &v);
                add_edge(u, v+1, 2);
                mins = min(mins, u);
                maxs = max(maxs, v+1);
        }
        for(int i=mins; i<maxs; i++) {
                add_edge(i, i+1, 0);
                add_edge(i+1, i, -1);
        }
        printf("%d\n", spfa(mins, maxs));

        return 0;
}
