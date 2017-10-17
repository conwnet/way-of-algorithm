#include <stdio.h>

int T, E, N, d[1100], u[4100], v[4100], w[4100];

int Bellman()
{
	int update = 1;
	for(int i=1; i<=N; i++) d[i] = 99999999;
	d[1] = 0;
	while(update) {
		update = 0;
		for(int i=0; i<E; i++) {
			if(d[v[i]] > d[u[i]] + w[i]) {
				d[v[i]] = d[u[i]] + w[i];
				update = 1;
			}
		}
	}
	return d[N];
}

int main()
{
	int tu, tv, tw;

	scanf("%d%d", &T, &N);
	E = 0;
	while(T--) {
		scanf("%d%d%d", &tu, &tv, &tw);
		u[E] = tu; v[E] = tv;
		w[E] = tw; E++;
		u[E] = tv; v[E] = tu;
		w[E] = tw; E++;
	}
	printf("%d\n", Bellman());

	return 0;
}