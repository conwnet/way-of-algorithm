#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int rank[205], N, K, ch;
int vst[205];
char S[205];


int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=1; i<=N; i++)
                        scanf("%d", &rank[i]);
                while(scanf("%d", &K) && K) {
                        getchar();
                        int n = 0;
                        while((ch=getchar())!='\n') S[++n] = ch;
                        while(n<N) S[++n] = ' ';
                        memset(vst, 0, sizeof(vst));
                        for(int i=1; i<=N; i++) {
                                int len = 0;
                                for(int j=i; !vst[j]; j=rank[j]) {
                                        vst[j] = 1; len++;
                                }
                                if(len>1) {
                                        int k = K%len;
                                        while(k--) {
                                                int t1 = S[i], t2, p = i;
                                                for(int j=0; j<len; j++) {
                                                        t2 = S[rank[p]];
                                                        S[rank[p]] = t1;
                                                        t1 = t2;
                                                        p = rank[p];
                                                }
                                        }
                                }
                        }
                        for(int i=1; i<=N; i++)
                                putchar(S[i]);
                        putchar('\n');
                }

        }

        return 0;
}
