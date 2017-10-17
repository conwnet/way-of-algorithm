#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
const int MAXN=33333;
const int INF=0xfffffff;
struct edge{int to,cost;};
typedef pair<int,int> pii;

int n,m;
int dis[MAXN];                 //用于保存1到各点的最短距离
vector<edge> v[MAXN];

int dij()
{
	priority_queue<pii> que;
	fill(dis+1,dis+n+1,INF);
	dis[1]=0;
	que.push(make_pair(0,1));

	while(!que.empty())
	{
		pii p=que.top();
		que.pop();

		if(dis[p.second]<p.first) continue;

		for(int i=0;i<v[p.second].size();++i)
		{
			edge e=v[p.second][i];
			if(dis[e.to]>dis[p.second]+e.cost)
			{
				dis[e.to]=dis[p.second]+e.cost;
				que.push(make_pair(dis[e.to],e.to));
			}
		}
	}
	return dis[n];
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int x;
		edge e;
		scanf("%d%d%d",&x,&e.to,&e.cost);
		v[x].push_back(e);               //用vector实现邻接表
	}
	printf("%d\n",dij());
	return 0;
}