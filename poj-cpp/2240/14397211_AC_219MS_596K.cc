#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> mp;
int N, M;
double G[40][40];


int main()
{
	char str[50];
	int a, b, ok, nCase = 0;
	double dis;

	while(scanf("%d", &N) && N) {
		mp.clear();
		memset(G, 0, sizeof(G));
		for(int i=1; i<=N; i++) {
			scanf("%s", str);
			mp[str] = i;
		}
		scanf("%d", &M);
		while(M--) {
			scanf("%s", str);
			a = mp[str];
			scanf("%lf%s", &dis, str);
			b = mp[str];
			G[a][b] = dis;
		}
		for(int k=1; k<=N; k++) {
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					G[i][j] = max(G[i][j], G[i][k]*G[k][j]);
				}
			}
		}
		ok = 0;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(G[i][j]*G[j][i]>1) ok = 1;
			}
		}
		printf("Case %d: ", ++nCase);
		if(ok==1) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}


