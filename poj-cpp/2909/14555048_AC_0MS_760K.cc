#include <stdio.h>
#include <math.h>
#include <string.h>

int prim[100005];

void get_prim()
{
	memset(prim, 0, sizeof(prim));
	prim[0] = prim[1] = 1;
	int n = sqrt(100000+0.5);
	for(int i=2; i<=n; i++) {
		if(prim[i]) continue;
		for(int j = i*i; j<100000; j+=i) {
			prim[j] = 1;
		}
	}
}

int main()
{
	get_prim();
	int n;
	
	while(scanf("%d", &n) && n) {
		int ans = 0;
		for(int i=2; i<=n/2; i++) {
			if(prim[i]) continue;
			if(!prim[n-i]) ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}