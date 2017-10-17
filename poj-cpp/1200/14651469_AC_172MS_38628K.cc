#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned long long ull;
const int maxl = 16*1024*1024+5;
const ull base = 100000007;
const ull modn = 8999993;

char str[maxl];
int next[maxl];
int N, NC;
int fir[modn];


int main()
{
        char ch;
        int l = 0;

        scanf("%d%d", &N, &NC);
        getchar();
        while((ch=getchar())!='\n')
                str[l++] = ch;
        memset(fir, -1, sizeof(fir));

        ull Mod = 1;
        for(int i=1; i<N; i++)
                Mod = Mod*base;

        ull ha = 0;
        for(int i=0; i<N; i++)
                ha = ha * base + str[i];
        next[0] = fir[ha%modn];
        fir[ha%modn] = 0;

        int ans = 1;
        for(int i=1; i<=l-N; i++) {
                ha = (ha-str[i-1]*Mod) * base + str[i+N-1];
                int t, flag = ha%modn;

                for(t=fir[flag]; t!=-1; t=next[t]) {
                        if(strncmp(&str[t], &str[i], N)==0)
                                break;
                }
                if(t==-1) {
                        ans++;
                        next[i] = fir[flag];
                        fir[flag] = i;
                }

        }
        printf("%d\n", ans);

        return 0;
}
