#include <stdio.h>
#include <algorithm>

using namespace std;

struct ADT {
        int a, b;
}cow[25010];

int N, T;

int cmp(ADT a, ADT b)
{
        if(a.a==b.a) return a.b<b.b;
        return a.a<b.a;
}

int main()
{
        int i, j, b, e, ans, cnt;

        scanf("%d%d", &N, &T);
        for(i=0; i<N; i++) scanf("%d%d", &cow[i].a, &cow[i].b);
        sort(cow, cow+N, cmp);
        if(cow[0].a>1) {
                printf("-1\n");
                return 0;
        }
        for(i=0; cow[i].a==1; i++) e =cow[i].b;
        ans = 1;
        while(e<T) {
                for(i=0, cnt=0; cow[i].a<=e && i<N; i++) cnt = max(cnt, cow[i].b);
                if(cnt==0) break;
                e = cnt;
                ans++;
                if(i==N) break;
        }
        if(e>=T) printf("%d\n", ans);
        else printf("-1\n");

        return 0;
}


/**<
5 10
1 5
2 3
2 10
3 5
7 15



 */
