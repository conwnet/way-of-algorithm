#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const double eps = 1e-4;
int N, K, a[1024], b[1024];
double tmp[1024];

int judge(double m)
{
	for(int i=0; i<N; i++)
		tmp[i] = a[i] - b[i]*m;
	sort(tmp, tmp+N);
	double sum = 0;
	for(int i=N-1; i>=K; i--)
		sum += tmp[i];
	return sum >= 0;
}

int main()
{
	//freopen("in", "r", stdin);
	while(scanf("%d%d", &N, &K)) {
		if(!N && !K) break;
		for(int i=0; i<N; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<N; i++)
			scanf("%d", &b[i]);
		double l = 0, r = 1e9;
		while(r-l > eps) {
			double m = (l+r) / 2;
			if(judge(m)) l = m;
			else r = m;
		}
		printf("%d\n", (int)(l*100+0.5));
	}

	return 0;
}


