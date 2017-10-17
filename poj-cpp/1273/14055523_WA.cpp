#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define MAXN 90000
#define INF 999999999

using namespace std;

long long flow[300][300], fl[90000], cap[300][300];

long long ek(long long st,long long ed,long long src,long long tar);

int main()
{
        long long M, N, i, a, b, c;

        while(~scanf("%lld%lld", &M, &N)){
                memset(cap, 0, sizeof(cap));
                for(int i=0; i<M; i++) {
                        scanf("%lld%lld%lld", &a, &b, &c);
                        if(a>b) a^=b^=a^=b;
                        cap[a][b] += c;
                }
                memset(flow, 0, sizeof(flow));
                printf("%lld\n", ek(1, M, 1, N));
        }

        return 0;
}

long long ek(long long st,long long ed,long long src,long long tar)//st ed 节点编号范围，src tar 源点 汇点
{
        long long res=0;
        long long pre[MAXN];
        long long mn[MAXN];

        memset(fl,0,sizeof(fl));
        while(1)
        {
                memset(pre,-1,sizeof(pre));
                mn[src]=INF;
                memset(fl,0,sizeof(fl));
                queue<long long> q;
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
