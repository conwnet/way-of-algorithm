#include <stdio.h>
#include <string.h>

const int maxn = 30;
int val[maxn], N, V, M, path[5], type[5], max_type, min_M, high;
int type_num(int n)
{
        int vst[30], cnt = 0;
        memset(vst, 0, sizeof(vst));
        for(int i=0; i<n; i++) {
                if(!vst[path[i]]) {
                        vst[path[i]] = 1;
                        cnt++;
                }
        }
        return cnt;
}

int cal_high(int *a, int n)
{
        int ret = a[0];
        for(int i=1; i<n; i++)
                if(a[i]>ret) ret = a[i];
        return ret;
}

int dfs(int s, int sum, int n)
{
        if(n==M) {
                if(sum==V) {
                        int t = type_num(M);
                        if(t>max_type) {
                                max_type = t; min_M = M; high = cal_high(path, M);
                                memcpy(type, path, sizeof(path));
                                return 1;
                        } else if(t==max_type && M<min_M) {
                                max_type = t; min_M = M; high = cal_high(path, M);
                                memcpy(type, path, sizeof(path));
                                return 1;
                        } else if(t==max_type && M==min_M && cal_high(path, M)>high) {
                                max_type = t; min_M = M; high = cal_high(path, M);
                                memcpy(type, path, sizeof(path));
                                return 1;
                        }
                }
                return 0;
        }
        for(int i=s; i<N; i++) {
                path[n] = i;
                dfs(i, sum+val[i], n+1);
        }
        return 0;
}

int same(int *a, int *b)
{
        for(int i=0; i<min_M; i++)
                if(a[i]!=b[i]) return 0;
        return 1;
}

int tie;
int dfs2(int s, int sum, int n)
{
        if(n==min_M) {
                if(sum==V) {
                        int t = type_num(min_M);
                        if(t==max_type && cal_high(path, min_M)==high) {

                                tie++;
                        }
                }
                return 0;
        }
        for(int i=s; i<N; i++) {
                path[n] = i;
                dfs2(i, sum+val[i], n+1);
        }
        return 0;
}

int main()
{
        while(~scanf("%d", &val[0])) {
                N = 1;
                while(scanf("%d", &val[N]) && val[N])
                        N++;
                while(scanf("%d", &V) && V) {
                        max_type = -1;
                        for(M=1; M<=4; M++)
                                dfs(0, 0, 0);
                        if(max_type<0) printf("%d ---- none\n", V);
                        else {
                                tie = 0;
                                dfs2(0, 0, 0);
                                printf("%d (%d):", V, max_type);
                                if(tie>1) printf(" tie\n");
                                else for(int i=0; i<min_M; i++) printf(" %d", val[type[i]]);
                                printf("\n");
                        }
                }

        }

        return 0;
}
