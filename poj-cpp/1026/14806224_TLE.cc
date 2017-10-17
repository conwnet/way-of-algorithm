#include <stdio.h>
#include <algorithm>

using namespace std;

int rank[205], N, K, ch;

struct Str{
        char ch;
        int r;
}S[205];

int cmp(Str A, Str B)
{
        return A.r < B.r;
}

int main()
{
        int len;
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        scanf("%d", &rank[i]);
                while(scanf("%d", &K) && K) {
                        getchar(); len = 0;
                        while((ch=getchar()) != '\n')
                                S[len++].ch = ch;
                        while(len<N) S[len++].ch = ' ';
                        while(K--) {
                                for(int i=0; i<N; i++)
                                        S[i].r = rank[i];
                                sort(S, S+N, cmp);
                        }
                        for(int i=0; i<N; i++)
                                putchar(S[i].ch);
                        putchar('\n');
                }
        }

        return 0;
}







