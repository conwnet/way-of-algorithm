#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

struct Edge {
        int to, cap, cost, rev;
        Edge(int a, int b, int c, int d):
                to(a), cap(b), cost(c), rev(d) {}
        Edge() {}
};

typedef pair<int, int> Pos;
const int maxv = 210;

int V;
vector<Edge> G[maxv];
int h[maxv], dis[maxv];
int prevv[maxv], preve[maxv];

void add_edge(int from, int to, int cap, int cost)
{
        G[from].push_back(Edge(to, cap, cost, G[to].size()));
        G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

/**
int min_cost_flow(int s, int t, int f)
{
        int res = 0;
        memset(h, 0, sizeof(h));
        while(f > 0) {
                priority_queue<Pos, vector<Pos>, greater<Pos> > que;
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                que.push(Pos(0, s));
                while(!que.empty()) {
                        Pos tmp = que.top();
                        que.pop();
                        int v = tmp.second;
                        if(dis[v]<tmp.first)
                                continue;
                        for(int i=0; i<G[v].size(); i++) {
                                Edge &e = G[v][i];
                                if(e.cap>0 && dis[e.to] > dis[v]+e.cost+h[v]-h[e.to]) {
                                        dis[e.to] = dis[v]+e.cost+h[v]-h[e.to];
                                        prevv[e.to] = v;
                                        preve[e.to] = i;
                                        que.push(Pos(dis[e.to], e.to));
                                }
                        }
                }
                if(dis[t]==INF) {
                        return -1;
                }
                for(int v=0; v<V; v++)
                        h[v] += dis[v];
                int d = f;
                for(int v=t; v!=s; v=prevv[v]) {
                        d = min(d, G[prevv[v]][preve[v]].cap);
                }
                f -= d;
                res += d*h[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        Edge &e = G[prevv[v]][preve[v]];
                        e.cap -= d;
                        G[v][e.rev].cap += d;
                }
        }
        return res;
}
*/

int min_cost_flow(int s, int t, int f)
{
        int res = 0;
        while(f > 0) {
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                bool update = true;
                while(update) {
                        update = false;
                        for(int v = 0; v<V; v++) {
                                if(dis[v]==INF) continue;
                                for(int i=0; i<G[v].size(); i++) {
                                        Edge &e = G[v][i];
                                        if(e.cap>0 && dis[e.to]>dis[v]+e.cost) {
                                                dis[e.to] = dis[v]+e.cost;
                                                prevv[e.to] = v;
                                                preve[e.to] = i;
                                                update = true;
                                        }
                                }
                        }
                }
                if(dis[t]==INF)
                        return 01;
                int d = f;
                for(int v=t; v!=s; v=prevv[v])
                        d = min(d, G[prevv[v]][preve[v]].cap);
                f -= d;
                res += d*dis[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        Edge &e = G[prevv[v]][preve[v]];
                        e.cap -= d;
                        G[v][e.rev].cap += d;
                }
        }
        return res;
}

char maps[105][105];
int N, M;
vector<Pos> man;
vector<Pos> hou;

int dist(Pos a, Pos b)
{
        return abs(a.first-b.first) + abs(a.second-b.second);
}

int main()
{
        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                memset(maps, 0, sizeof(maps));
                for(int i=1; i<=N; i++)
                        scanf("%s", maps[i]+1);
                man.clear();
                hou.clear();
                for(int i=1; i<=N; i++) {
                        for(int j=1; j<=M; j++) {
                                if('m'==maps[i][j])
                                        man.push_back(Pos(i, j));
                                else if('H'==maps[i][j])
                                        hou.push_back(Pos(i, j));
                        }
                }
                for(int i=0; i<maxv; i++)
                        G[i].clear();
                for(int i=0; i<man.size(); i++) {
                        for(int j=0; j<hou.size(); j++) {
                                add_edge(i+1, man.size()+j+1, 1, dist(man[i], hou[j]));
                        }
                }
                V = man.size()+hou.size()+2;
                for(int i=0; i<man.size(); i++)
                        add_edge(0, i+1, 1, 0);
                for(int i=0; i<hou.size(); i++)
                        add_edge(man.size()+i+1, V-1, 1, 0);
                printf("%d\n", min_cost_flow(0, V-1, man.size()));
        }

        return 0;
}



