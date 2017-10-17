#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int u[10010], v[10010], w[10010], r[10010], p[10010];
int N, M, mark;
queue<int> Q;

int findp(int x)
{
	return x==p[x]?x:p[x]=findp(p[x]);
}

int cmp(int x, int y)
{
	return w[x] < w[y];
}

int get_kruskal()
{
	int sum = 0;
	for(int i=0; i<=N; i++) p[i] = i;
	for(int i=0; i<M; i++) r[i] = i;
	sort(r, r+M, cmp);
	for(int i=0; i<M; i++) {
		int t = r[i];
		int x = findp(u[t]);
		int y = findp(v[t]);
		if(x!=y) {
			p[x] = y;
			sum += w[t];
			Q.push(t);
		}
	}

	return sum;
}

int kruskal()
{
	int sum = 0, cnt = 0;;
	for(int i=0; i<=N; i++) p[i] = i;
	for(int i=0; i<M; i++) {
		int t = r[i];
		if(t==mark) continue;
		int x = findp(u[t]);
		int y = findp(v[t]);
		if(x!=y) {
			cnt ++;
			p[x] = y;
			sum += w[t];
		}
	}
	if(cnt!=N-1) return -1;
	return sum;
}

int main()
{
	int T, faild, ans;

	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i=0; i<M; i++) {
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
		}
		faild = 0;
		ans = get_kruskal();
		while(!Q.empty()) {
			mark = Q.front();
			Q.pop();
			if(!faild && ans==kruskal()) faild = 1;
		}
		if(faild) printf("Not Unique!\n");
		else printf("%d\n", ans);
	}

	return 0;
}
