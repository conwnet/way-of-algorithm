#include <stdio.h>
#include <algorithm>

using namespace std;

struct Cow {
        int st;
        int et;
        int w;
        bool operator < (const Cow oth) const {
                if(st==oth.st) return et<oth.et;
                return st<oth.st;
        }
}cow[1100];

int N, M, R;

int dfs(int num, int to);

int main()
{
        int i, j;

        scanf("%d%d%d", &N, &M, &R);
        for(i=0; i<M; i++) scanf("%d%d%d", &cow[i].st, &cow[i].et, &cow[i].w);
        sort(cow, cow+M);
        printf("%d\n", dfs(0, 0));

        return 0;
}

int dfs(int num, int to)
{
        int res = 0;

        while(cow[num].st<to+R && num<M) num++;
        if(num==M) return 0;
        res = max(dfs(num+1, 0), dfs(num+1, cow[num].et)+cow[num].w);
        return res;
}
