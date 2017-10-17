#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int bit[100005], S[100005], T[100005], val[100005], N;
vector<int> G[100005];

inline int lowbit(int x)
{
	return x&-x;
}

void change(int pos, int n)
{
	while(pos<=N) {
		bit[pos] += n;
		pos += lowbit(pos);
	}
}

int sum(int pos)
{
	int s = 0;
	while(pos>0) {
		s += bit[pos];
		pos -= lowbit(pos);
	}
	return s;
}

int num = 0;

void dfs(int n)
{
	S[n] = ++num;
	for(int i=0; i<G[n].size(); i++) {
		dfs(G[n][i]);
	}
	T[n] = num;
}

int main()
{
	int u, v, i, Q;
	char op[5];

	scanf("%d", &N);
	for(i=1; i<N; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	dfs(1);
	memset(val, 0, sizeof(val));
	for(i=1; i<=N; i++) change(i, 1);
	scanf("%d", &Q);
	while(Q--) {
		getchar();
		scanf("%s%d", op, &u);
		if(op[0]=='C') {
			if(val[u]) change(S[u], 1);
			else change(S[u], -1);
			val[u] = !val[u];
		} else
			printf("%d\n", sum(T[u])-sum(S[u]-1));
	}

	return 0;
}

