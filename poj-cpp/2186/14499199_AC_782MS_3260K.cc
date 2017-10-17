#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int dfn[10005], low[10005], stack[10005], top, Dindex;
int instack[10005], belong[10005], cnt, N, M;
vector<int> G[10005], G2[100005];

int tarjan(int u)
{
	stack[++top] = u;
	dfn[u] = low[u] = ++Dindex;
	instack[u] = 1;
	for(int i=0; i<G[u].size(); i++) {
		int v = G[u][i];
		if(!dfn[v]) {
			tarjan(v);
			if(low[v]<low[u])
				low[u] = low[v];
		} else if(instack[v] && dfn[v]<low[u]) {
			low[u] = dfn[v];
		}
	}
	if(dfn[u]==low[u]) {
		int v;
		cnt++;
		do {
			v = stack[top--];
			instack[v] = 0;
			belong[v] = cnt;
		} while(u!=v);
	}
}

int main()
{
	int u, v, ans;

	top = cnt = Dindex = 0;
	scanf("%d%d", &N, &M);
	while(M--) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	for(int i=1; i<=N; i++) {
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=1; i<=N; i++) {
		for(int j=0; j<G[i].size(); j++) {
			int v = G[i][j];
			if(belong[v]!=belong[i])
				G2[belong[i]].push_back(v);
		}
	}
	int tmp = 0;
	for(int i=1; i<=cnt; i++) {
		if(G2[i].size()==0) {
			ans = i;
			tmp++;
		}
	}
	if(tmp>1) printf("0\n");
	else {
		tmp = 0;
		for(int i=1; i<=N; i++)
			if(belong[i]==ans)
				tmp++;
		printf("%d\n", tmp);
	}

	return 0;
}








