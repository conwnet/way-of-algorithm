#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 100000;
const int MOD =  100000;
int ch[maxn][4], val[maxn], nc;
char maps[5] = "ACGT";
int idx(char c)
{
        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='G') return 2;
        return 3;
}

void add_str(char *str, int v)
{
        int p = 0;
        for(int i=0; str[i]; i++) {
                int id = idx(str[i]);
                if(!ch[p][id]) ch[p][id] = ++nc;
                p = ch[p][id];
        }
        val[p] = v;
}

int fa[maxn], la[maxn];

void get_fail()
{
        queue<int> que;
        for(int i=0; i<4; i++) {
                int u = ch[0][i];
                if(u) { que.push(u); }
        }
        while(!que.empty()) {
                int r = que.front(); que.pop();
                for(int i=0; i<4; i++) {
                        int u = ch[r][i];
                        int v = fa[r];
                        if(!u) { ch[r][i] = ch[v][i]; continue; }
                        que.push(u);
                        while(v && !ch[v][i]) v = fa[v];
                        fa[u] = ch[v][i];
                        la[u] = val[fa[u]] ? fa[u] : la[fa[u]];
                }
        }
}

typedef long long ll;
struct Mat{
        ll num[200][200], r, c;
}mat, ans;

void get_mat()
{
        int r = 0, c = 0;
        for(int i=0; i<=nc; i++) {
                for(int j=0; j<4; j++)
                        mat.num[i][ch[i][j]]++;
        }
        mat.r = nc+1; mat.c = nc+1;
}

void del_mat()
{
        for(int i=0; i<mat.r; i++) {
                if(val[i]) {
                        for(int j=0; j<mat.r; j++)
                                mat.num[i][j] = mat.num[j][i] = 0;
                }
        }
}

Mat t;
void mul_mat(Mat A, Mat B)
{
        memset(t.num, 0, sizeof(t.num));
        for(int i=0; i<mat.r; i++) {
                for(int j=0; j<mat.r; j++) {
                        for(int k=0; k<mat.r; k++)
                                t.num[i][j] += A.num[i][k]*B.num[k][j];
                                t.num[i][j] %= MOD;
                }
        }
        /**
        for(int i=0; i<mat.r; i++) {
                for(int j=0; j<mat.r; j++)
                        printf("%d ", A.num[i][j]);
                printf("\n");
        }
        for(int i=0; i<mat.r; i++) {
                for(int j=0; j<mat.r; j++)
                        printf("%d ", B.num[i][j]);
                printf("\n");
        }
        for(int i=0; i<mat.r; i++) {
                for(int j=0; j<mat.r; j++)
                        printf("%d ", t.num[i][j]);
                printf("\n");
        }
        */
}

Mat t1;
void pow_mat(Mat A, int n)
{
        memset(t1.num, 0, sizeof(t1.num));
        for(int i=0; i<mat.r; i++) t1.num[i][i] = 1;
        while(n) {
                if(n&1) {
                        mul_mat(t1, A);
                        t1 = t;
                }
                n >>= 1;
                mul_mat(A, A);
                A = t;
        }
}

int M, N;
int main()
{
        char str[20];
        scanf("%d%d", &M, &N);
        for(int i=1; i<=M; i++) {
                scanf("%s", str);
                add_str(str, i);
        }
        get_fail();
        get_mat();
        del_mat();
        pow_mat(mat, N);
        ans = t1;
        ll res = 0;

        for(int i=0; i<mat.r; i++) {
                res += ans.num[0][i];
                res %= MOD;
        }
        printf("%lld\n", res);

        return 0;
}








