#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> index;

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
map<index, int> mp;

int dfs(int num, int to);

int main()
{
        int i, j;

        mp.clear();
        scanf("%d%d%d", &N, &M, &R);
        for(i=0; i<M; i++) scanf("%d%d%d", &cow[i].st, &cow[i].et, &cow[i].w);
        sort(cow, cow+M);
        printf("%d\n", dfs(0, 0));

        return 0;
}

int dfs(int num, int to)
{
        int res = 0;

        if(mp[index(num, to)]!=0) return mp[index(num, to)];
        while(cow[num].st<to && num<M) num++;
        if(num==M) return 0;
        res = max(dfs(num+1, 0), dfs(num+1, cow[num].et+R)+cow[num].w);
        return mp[index(num, to)] = res;
}



/**<
12 1 2
1 2 8


 */




