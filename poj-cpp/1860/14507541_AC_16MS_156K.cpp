#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M, S, u[220], v[220];
double uv[220], uc[220], d[110], A;

int bellman(int s, double n)
{
	d[s] = n;
	for(int i=1; i<=N; i++) {
		for(int j=0; j<M*2; j++) {
			if(d[u[j]]<uc[j]) continue;
			double t = (d[u[j]]-uc[j]) * uv[j];
			if(t > d[v[j]]) {
				d[v[j]] = t;
				if(i == N) return 1;
			}
		}
	}
	return 0;
}

int main()
{
	for(int i=0; i<=N; i++) d[i] = -1;
	scanf("%d%d%d%lf", &N, &M, &S, &A);
	for(int i=0; i<M; i++) {
		scanf("%d%d%lf%lf", &u[i], &v[i], &uv[i], &uc[i]);
		u[i+M] = v[i]; v[i+M] = u[i];
		scanf("%lf%lf", &uv[i+M], &uc[i+M]);
	}
	if(bellman(S, A)) printf("YES\n");
	else printf("NO\n");

	return 0;
}