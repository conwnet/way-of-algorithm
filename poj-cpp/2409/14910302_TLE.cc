#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int N, C;
int val[100000], ch[100000][26], nc;

void add_str(int *arr, int len)
{
        int p = 0;
        for(int i=0; i<len; i++) {
                int v = arr[i];
                if(!ch[p][v])
                        ch[p][v] = nc++;
                p = ch[p][v];
        }
        val[p] = 1;
}

int finds(int *arr, int len)
{
        int p = 0;
        for(int i=0; i<len; i++) {
                int v = arr[i];
                if(!ch[p][v]) return 0;
                p = ch[p][v];
        }
        if(val[p]) return 1;
}

int tmp[20], path[20];
int judge(int len)
{
        for(int i=0; i<len; i++) {
                for(int j=0; j<len; j++) {
                        tmp[j] = path[(i+j)%N];
                }
                if(finds(tmp, len)) return 0;
        }
        return 1;
}

int ans;
int dfs(int m)
{
        if(m==N) {
                if(judge(N)) {
                        add_str(path, N);
                        ans++;
                }
        } else {
                for(int i=0; i<C; i++) {
                        path[m] = i;
                        dfs(m+1);
                }
        }
}

int main()
{
        while(scanf("%d%d", &C, &N)) {
                nc = 1;
                memset(ch, 0, sizeof(ch));
                memset(val, 0, sizeof(val));
                ans = 0;
                dfs(0);
                printf("%d\n", ans);
        }

        return 0;
}
