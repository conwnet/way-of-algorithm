#include <stdio.h>

int main()
{
	int N, v, t, ans;
	double time;

	while(scanf("%d", &N) && N) {
		ans = 99999;
		while(N--) {
			scanf("%d%d", &v, &t);
			if(t<0) continue;
			time = 4500/(v/3.6) + t;
			if(time-(int)time>0) time++;
			if((int)time<ans) ans = (int)time;
		}
		printf("%d\n", ans);
	}

	return 0;
}
