#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAXN 500

using namespace std;

int flow[500][500], fl[250000], cap[500][500];

int ek(int st,int ed,int src,int tar);

int main()
{
        int N, M, i, j, n, t;

        while(~scanf("%d%d", &N, &M)) {
                memset(cap, 0, sizeof(cap));
                for(i=1; i<=N; i++) cap[0][i] = 1;
                for(i=1; i<=M; i++) cap[N+i][N+M+1] = 1;
                for(i=1; i<=N; i++) {
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d", &t);
                                cap[i][N+t] = 1;
                        }
                }
                memset(flow, 0, sizeof(flow));
                printf("%d\n", ek(0, M+N+1, 0, M+N+1));
        }

        return 0;
}

int ek(int st,int ed,int src,int tar)
{
        int res = 0;
        int pre[MAXN];
        int mn[MAXN];

        memset(fl,0,sizeof(fl));
        while(1)
        {
                memset(pre,-1,sizeof(pre));
                mn[src]=INF;
                memset(fl,0,sizeof(fl));
                queue<int> q;
                q.push(src);
                while(!q.empty())
                {
                        int t=q.front();
                        q.pop();
                        if(fl[t])continue;
                        fl[t]=1;
                        for(int i=st;i<=ed;i++)
                        {
                                if(!fl[i]&&cap[t][i]-flow[t][i]>0)
                                {
                                        pre[i]=t;
                                        mn[i]=min(cap[t][i]-flow[t][i],mn[t]);
                                        q.push(i);
                                }
                        }
                        if(pre[tar]!=-1)
                        {
                                for(int i=tar;pre[i]!=-1;i=pre[i])
                                {
                                        flow[pre[i]][i]+=mn[tar];
                                        flow[i][pre[i]]-=mn[tar];
                                }
                                break;
                        }
                }
                if(pre[tar]==-1)break;
                else res+=mn[tar];
        }

        return res;
}
