#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int f[110000], V;

void zo_pack(int c);
void com_pack(int c);
void mul_pack(int c, int m);

int main()
{
        int N, m[20], c[20], maxs;

        while(~scanf("%d%d", &V, &N)) {
                for(int i=0; i<N; i++) {
                        scanf("%d%d", &m[i], &c[i]);
                }
                memset(f, 0, sizeof(f));
                for(int i=0; i<N; i++)
                        mul_pack(c[i], m[i]);
                maxs = 0;
                //for(int i=0; i<=V; i++) maxs = max(maxs, f[i]);
                printf("%d\n", f[V]);
        }

        return 0;
}

void zo_pack(int c)
{
        for(int i=V; i>=c; i--) {
                f[i] = max(f[i], f[i-c]+c);
        }
}

void com_pack(int c)
{
        for(int i=c; i<=V; i++) {
                f[i] = max(f[i], f[i-c]+c);
        }
}

void mul_pack(int c, int m)
{
        if(c*m>=V) {
                com_pack(c);
                return ;
        }
        for(int k=1; k<m; k*=2) {
                zo_pack(c*k);
                m -= k;
        }
        zo_pack(m*c);
}






