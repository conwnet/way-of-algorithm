#include <stdio.h>
#define INF 9999999

int u[5500], v[5500], w[5500], d[5500], N, M, W, E;

int BellmanFord()
{
        for(int i=2; i<=N; i++) d[i] = INF;
        d[1] = 0;
        for(int i=0; i<N; i++) {
                for(int j=0; j<E; j++) {
                        if(d[v[j]]>d[u[j]]+w[j]) {
                                d[v[j]] = d[u[j]] + w[j];
                                if(i==N-1) return 1;
                        }
                }
        }
        return 0;
}

int main()
{
        int T, tu, tv, tw;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d%d", &N, &M, &W);
                E = 0;
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &tu, &tv, &tw);
                        u[E] = tu; v[E] = tv;
                        w[E] = tw; E++;
                        v[E] = tu; u[E] = tv;
                        w[E] = tw; E++;
                }
                for(int i=0; i<W; i++) {
                        scanf("%d%d%d", &tu, &tv, &tw);
                        u[E] = tu; v[E] = tv;
                        w[E] = -tw; E++;
                }
                if(BellmanFord()) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
