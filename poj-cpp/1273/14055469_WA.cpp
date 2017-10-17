#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define MAXN 300
#define INF 9999999

using namespace std;

unsigned int flow[300][300], fl[300], cap[300][300];

unsigned int ek(unsigned int st,unsigned int ed,unsigned int src,unsigned int tar);

int main()
{
        unsigned int M, N, i, a, b, c;

        while(~scanf("%d%d", &M, &N)){
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &a, &b, &c);
                        cap[a][b] = c;
                }
                memset(flow, 0, sizeof(flow));
                printf("%d\n", ek(1, M, 1, N));
        }

        return 0;
}

unsigned int ek(unsigned int st,unsigned int ed,unsigned int src,unsigned int tar)//st ed 节点编号范围，src tar 源点 汇点
{
        unsigned int res=0;
        unsigned int pre[MAXN];
        unsigned int mn[MAXN];

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
