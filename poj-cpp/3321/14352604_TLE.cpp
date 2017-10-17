#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100005;

int fir[maxn], next[maxn*2];
int N, Q, sum[maxn], val[maxn], p[maxn];

void init();
void change(int x);

int main()
{
        int i, u, v, t;
        char cmd[5];
        queue<int> que;

        scanf("%d", &N);
        memset(p, 0, sizeof(p));
        memset(fir, -1, sizeof(fir));
        for(i=1; i<N; i++) {
                scanf("%d%d", &u, &v);
                p[v] = u;
             ///   next[i+maxn] = fir[v[i]];
             ///   fir[v[i]] = i+maxn;
        }
    //    1 2
     //   1 3


        /**
        que.push(1);
        while(!que.empty()) {
                int top = que.front(); que.pop();
                for(i=fir[top]; i!=-1; i=next[i]) {
                        int n = (top==u[i]?v[i]:top);
                        if(n != p[top]) {
                                p[n] = top;
                                que.push(n);
                        }
                }
        }
        */
     ///   for(i=1; i<=N; i++) printf("%d==", p[i]);
        init();
        scanf("%d", &Q);
        while(Q--) {
                scanf("%s%d", cmd, &t);
                if(cmd[0]=='C') {
                        change(t);
                } else {
                        printf("%d\n", sum[t]);
                }
        }


        return 0;
}

void init()
{
        int i;

        for(i=1; i<=N; i++) val[i] = 1;
        memset(sum, 0, sizeof(sum));
        for(i=1; i<=N; i++) {
                int t = i;
                while(t!=0) {
                        sum[t]++;
                        t = p[t];
                }
        }
}

void change(int x)
{
        if(val[x]==1) {
                val[x] = 0;
                int t = x;
                while(t!=0) {
                        sum[t]--;
                        t = p[t];
                }
        } else {
                val[x] = 1;
                int t = x;
                while(t!=0) {
                        sum[t]++;
                        t = p[t];
                }
        }
}




