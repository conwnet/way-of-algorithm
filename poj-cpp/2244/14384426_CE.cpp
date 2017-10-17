#include <stdio.h>

int next[160], N;

int main()
{
	int m, i, j, t;

	while(~scanf("%d", &N) && N) {
		m = 1;
		while(m++) {
			for(i=1; i<N; i++) next[i] = i+1;
			next[N] = 1;
			for(i=1, t=N; i<N; i++) {
				if(next[t]==2) break;
				next[t] = next[next[t]];
				for(j=1; j<m; j++) {
					t = next[t];
				}
			}
			if(i==N) break;
		}
		printf("%d\n", m);
	}

	return 0;
}


// 1 2 3 4