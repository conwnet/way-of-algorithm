#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 300000;
int ch[maxn][4], las[maxn], val[maxn], fai[maxn], ccnt = 1;

int index(char c)
{
        if(c=='A') return 0;
        if(c=='T') return 1;
        if(c=='C') return 2;
        if(c=='G') return 3;
}

void insert(char *str) {
        int p = 0;
        for(int i=0; str[i]; i++) {
                int c = index(str[i]);
                if(!ch[p][c])
                        ch[p][c] = ccnt++;
                p = ch[p][c];
        }
        val[p] = 1;
}

void print(int j) {
        if(j) printf("1\n");
        if(las[j]) print(las[j]);
}

void find(char *T) {
        int len = strlen(T);
        int j = 0;
        for(int i=0; i<len; i++) {
                int c = index(T[i]);
                j = ch[j][c];
                if(val[j]) print(j);
                else if(las[j]) print(las[j]);
        }
}

int get_fail() {
        queue<int> que;
        fai[0] = 0;
        for(int c=0; c<4; c++) {
                int u = ch[0][c];
                if(u) { fai[u] = 0; que.push(u); las[u] = 0; }
        }
        while(!que.empty()) {
                int r = que.front(); que.pop();
                if(las[r]) val[r] = 1;
                for(int c=0; c<4; c++) {
                        int u = ch[r][c];
                        if(!u) { ch[r][c] = ch[fai[r]][c]; continue; }
                        que.push(u);
                        int v = fai[r];
                        while(v && !ch[v][c]) v = fai[v];
                        fai[u] = ch[v][c];
                        las[u] = val[fai[u]] ? fai[u] : las[fai[u]];
                }
        }
}

int N, M;
long long mat[1024][1024], ans[1024][1024], tmp[1024][1024];

void ans_mul()
{
        memset(tmp, 0, sizeof(tmp));
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<ccnt; j++) {
                        for(int k=0; k<ccnt; k++) {
                                tmp[i][j] += ans[i][k]*mat[k][j];
                        }
                        tmp[i][j] %= 100000;
                }
        }
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<ccnt; j++)
                        ans[i][j] = tmp[i][j];
        }
}

void mat_mul()
{
        memset(tmp, 0, sizeof(tmp));
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<ccnt; j++) {
                        for(int k=0; k<ccnt; k++) {
                                tmp[i][j] += mat[i][k]*mat[k][j];
                        }
                        tmp[i][j] %= 100000;
                }
        }
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<ccnt; j++)
                        mat[i][j] = tmp[i][j];
        }
}

int mat_pow(int m)
{
        for(int i=0; i<ccnt; i++)
                ans[i][i] = 1;
        while(m) {
                if(m&1) ans_mul();
                mat_mul();
                m >>= 1;
        }
}


int main() {
        char str[15];

        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                scanf("%s", str);
                insert(str);
        }
        get_fail();
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<4; j++) {
                        if(!val[i] && !val[ch[i][j]])
                                mat[i][ch[i][j]]++;
                }
        }
        mat_pow(M);
        /**
        for(int i=0; i<ccnt; i++) {
                for(int j=0; j<ccnt; j++)
                        printf("%d ", ans[i][j]);
                printf("\n");
        }
        */
        int ret = 0;
        for(int i=0; i<ccnt; i++)
                ret += ans[0][i];
        printf("%d\n", ret%100000);

        return 0;
}



