#include <stdio.h>
#include <string.h>

const int maxn = 20603;

struct Edge {
        int to, cost, next;
} edge[maxn*100];
int N, M, dis[maxn], fir[maxn], ec;

void add_edge(int u, int v, int w)
{
        edge[ec] = (Edge){v, w, fir[u]};
        fir[u] = ec++;
}

const int qsize = maxn;
int que[maxn], front, tail;
void push(int n) { que[tail++]=n; tail %= qsize; }
void pop() { front++; front %= qsize; }
int spfa(int s)
{
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0;
        front = tail = 0;
        push(s);
        while(front!=tail) {
                int u = que[front]; pop();
                for(int i=fir[u]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(dis[u]+e.cost < dis[e.to]) {
                                dis[e.to] = dis[u]+e.cost;
                                push(e.to);
                        }
                }
        }
        int ret = 0;
        for(int i=1; i<=N; i++) {
                ret += dis[i];
        }
        return ret;
}

int main()
{
        int n, u, v;
        memset(fir, -1, sizeof(fir)); ec = 0;
        scanf("%d%d", &N, &M);
        for(int i=1; i<=M; i++) {
                scanf("%d", &n);
                for(int j=0; j<n; j++) {
                        scanf("%d", &u);
                        add_edge(u, N+i, 1);
                        add_edge(N+i, u, 1);
                }
        }
        int ans = 0x3f3f3f3f;
        for(int i=1; i<=N; i++) {
                int t = spfa(i);
                if(t < ans) ans = t;
        }
        printf("%d\n", ans*50/(N-1));

        return 0;
}
