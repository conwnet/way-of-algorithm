#include <iostream>  
#include <cstdio>  
#include <climits>  
#include <algorithm>  
#include <queue>  
using namespace std;  
  
const int N = 30005;  
const int E = 150005;  
const int MAX = 1000000000;  
  
struct Edge  
{  
    int pnt;  
    int dis;  
    int next;  
}edge[E];  
int cur;  
int neigh[N];  
int n, e;  
int mindis[N];  
bool vis[N];  
struct Qnode  
{  
    int pnt;  
    int dis;  
    Qnode(int _pnt, int _dis): pnt(_pnt), dis(_dis){}  
    bool operator < (const Qnode& node) const  
    {  
        return dis > node.dis;  
    }  
};  
  
void init()  
{  
    cur = 0;  
    for (int i = 0; i < n; ++i) neigh[i] = -1;  
}  
  
void addedge(int beg, int end, int dis)  
{  
    edge[cur].pnt = end;  
    edge[cur].dis = dis;  
    edge[cur].next = neigh[beg];  
    neigh[beg] = cur;  
    ++cur;  
}  
  
void dijkstra(int s)  
{  
    int pre, te, pnt;  
    for (int i = 0; i < n; ++i)  
    {  
        mindis[i] = MAX;  
        vis[i] = false;  
    }  
    mindis[s] = 0;  
    vis[s] = true;  
    priority_queue<Qnode> pq;  
    pq.push(Qnode(s, 0));  
    pre = s;  
    for (int i = 1; i < n; ++i)  
    {  
        te = neigh[pre];  
        while (te != -1)  
        {  
            pnt = edge[te].pnt;  
            if (!vis[pnt] && mindis[pre] + edge[te].dis < mindis[pnt])  
            {  
                mindis[pnt] = mindis[pre] + edge[te].dis;  
                pq.push(Qnode(pnt, mindis[pnt]));  
            }  
            te = edge[te].next;  
        }  
        while (!pq.empty() && vis[pq.top().pnt]) pq.pop();  
        pre = pq.top().pnt;  
        vis[pre] = true;  
        pq.pop();  
    }  
}  
  
int main()  
{  
    int beg, end, dis;  
    scanf("%d%d", &n, &e);  
    init();  
    for (int i = 0; i < e; ++i)  
    {  
        scanf("%d%d%d", &beg, &end, &dis);  
        --beg;  
        --end;  
        addedge(beg, end, dis);  
    }  
    dijkstra(0);  
    printf("%d\n", mindis[n - 1]);  
    return 0;  
}  