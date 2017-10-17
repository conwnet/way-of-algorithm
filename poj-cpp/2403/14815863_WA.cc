#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 300000;
int ch[maxn][27], val[maxn], nc;

void add_str(char *str, int v)
{
        int p = 0;
        for(int i=0; str[i]; i++) {
                int id = str[i]-'a';
                if(!ch[p][id])
                        ch[p][id] = ++nc;
                p = ch[p][id];
        }
        val[p] = v;
}

int fa[maxn], la[maxn];

void get_fail()
{
        queue<int> que;
        for(int c=0; c<27; c++) {
                int u = ch[0][c];
                if(u) que.push(u);
        }
        while(!que.empty()) {
                int r = que.front(); que.pop();
                for(int c=0; c<27; c++) {
                        int u = ch[r][c];
                        if(!u) {
                                //ch[r][c] = ch[fa[r]][c];
                                continue;
                        }
                        que.push(u);
                        int v = fa[r];
                        while(v && !ch[v][c]) v = fa[v];
                        fa[u] = ch[v][c];
                        la[u] = val[fa[u]] ? fa[u] : la[fa[u]];
                }
        }
}

int ans;
void print(int p)
{
        if(p) {
                ans += val[p];
                //printf("%d\n", val[p]);
                print(la[p]);
        }
}

int find_str(char *str)
{
        int p = 0, c;
        ans = 0;
        for(int i=0; str[i]; i++) {
                if(str[i]=='\n' || str[i]==' ') str[i] = 'a'+26;
                int id = str[i]-'a';
                while(p && !ch[p][id]) p = fa[p];
                p = ch[p][id];
                if(val[p]) print(p);
                else if(la[p]) print(la[p]);
        }
        return ans;
}

char str[maxn];

int main()
{
        int N, M, v;

        scanf("%d%d", &N, &M);
        while(N--) {
                scanf("%s%d", str, &v);
                add_str(str, v);
        }
        while(M--) {
                scanf("%[^.]%*c", str);
                printf("%d\n", find_str(str));
        }

        return 0;
}

/**<
4 100
a 1
b 2
c 3
d 4



 */














