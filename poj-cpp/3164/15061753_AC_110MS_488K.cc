#include <stdio.h>
#include <math.h>
#include <string.h>

#define CL(arr, val)    memset(arr, val, sizeof(arr))
#define REP(i, n)       for((i) = 0; (i) < (n); ++(i))

const double eps = 1e-6;
const double inf = 0x3f3f3f3f;

const int N = 110;
const int M = 10010;

struct node {
    double x, y;
} point[N];

struct edg {
    int u, v;
    double cost;
} E[M];

double In[N];
int ID[N];
int vis[N];
int pre[N];
int NV, NE;

double SQ(int u, int v) {
    return sqrt((point[u].x - point[v].x)*(point[u].x - point[v].x) +
                (point[u].y - point[v].y)*(point[u].y - point[v].y));
}

double Directed_MST(int root) {
    double ret = 0;
    int i, u, v;
    while(true) {
        REP(i, NV)   In[i] = inf;
        REP(i, NE) {    //找最小入边
            u = E[i].u;
            v = E[i].v;
            if(E[i].cost < In[v] && u != v) {
                In[v] = E[i].cost;
                pre[v] = u;
            }
        }
        REP(i, NV) {    //如果存在除root以外的孤立点，则不存在最小树形图
            if(i == root)   continue;
            if(In[i] == inf)    return -1;
        }

        int cnt = 0;
        CL(ID, -1);
        CL(vis, -1);
        In[root] = 0;

        REP(i, NV) {    //找环
            ret += In[i];
            int v = i;
            while(vis[v] != i && ID[v] == -1 && v != root) {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && ID[v] == -1) {  //重新标号
                for(u = pre[v]; u != v; u = pre[u]) {
                    ID[u] = cnt;
                }
                ID[v] = cnt++;
            }
        }
        if(cnt == 0)    break;
        REP(i, NV) {
            if(ID[i] == -1) ID[i] = cnt++;    //重新标号
        }
        REP(i, NE) {    //更新其他点到环的距离
            v = E[i].v;
            E[i].u = ID[E[i].u];
            E[i].v = ID[E[i].v];
            if(E[i].u != E[i].v) {
                E[i].cost -= In[v];
            }
        }
        NV = cnt;
        root = ID[root];
    }
    return ret;
}

int main()
{
        int u, v;
        while(~scanf("%d%d", &NV, &NE)) {
                for(int i=0; i<NV; i++)
                        scanf("%lf%lf", &point[i].x, &point[i].y);
                for(int i=0; i<NE; i++) {
                        scanf("%d%d", &u, &v);
                        pre[v-1] = u-1;
                        E[i].u = u-1;
                        E[i].v = v-1;
                        E[i].cost = SQ(u-1, v-1);
                }
                double ans = Directed_MST(0);
                if(ans < 0) printf("poor snoopy\n");
                else printf("%.2f\n", ans);
        }

        return 0;
}
