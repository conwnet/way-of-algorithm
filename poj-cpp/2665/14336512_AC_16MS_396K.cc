#include <stdio.h>
#include <algorithm>

using namespace std;

struct ADT{
        int s, t;
} sec[5010];
int L, M;

int cmp(ADT A, ADT B)
{
        if(A.s!=B.s) return A.s < B.s;
        return A.t < B.t;
}

int main()
{
        int i, S, T;

        while(scanf("%d%d", &L, &M)) {
                if(L==0 && M==0) break;
                for(i=0; i<M; i++) scanf("%d%d", &sec[i].s, &sec[i].t);
                sort(sec, sec+M, cmp);
                S = 0;
                for(i=0; i<M; i++) {
                        if(sec[i].t>S) {
                                if(sec[i].s > S) S = sec[i].s-1;
                                L -= sec[i].t-S;
                                S = sec[i].t;
                        }
                }
                printf("%d\n", L+1);
        }

        return 0;
}
