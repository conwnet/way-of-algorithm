
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define INF 99999999

using namespace std;

int f[100010], c[1024], w[1024], m[1024], N, V;

void zo_pack(int f[], int c, int w);
void com_pack(int f[], int c, int w);
void mul_pack(int f[], int c, int w, int m);

int main()
{
        int i, cnt;

       for(i=0; i<1024; i++) w[i] = 1;
        while(scanf("%d%d", &N, &V) && (N || V)) {
                cnt = 0;
                for(i=0; i<N; i++) scanf("%d", &c[i]);
                for(i=0; i<N; i++) scanf("%d", &m[i]);
                for(i=0; i<V+1; i++) f[i] = -INF;

                f[0] = 0;
                for(i=0; i<N; i++) {
                        mul_pack(f, c[i], w[i], m[i]);
                }
                for(i=1; i<=V; i++) if(f[i]>=0) cnt++;
                printf("%d\n", cnt);
        }

        return 0;
}

void zo_pack(int f[], int c, int w)
{
        for(int i=V; i>=c; i--) {
                f[i] = max(f[i], f[i-c]+w);
        }
}

void com_pack(int f[], int c, int w)
{
        for(int i=c; i<=V; i++) {
                f[i] = max(f[i], f[i-c]+w);
        }
}

void mul_pack(int f[], int c, int w, int m)
{
        if(c*m>V) {
                com_pack(f, c, w);
                return ;
        }
        for(int k=1; k<m; ) {
                zo_pack(f, k*c, k*w);
                m = m-k;
                k *= 2;
        }
        zo_pack(f, c, w);
}





