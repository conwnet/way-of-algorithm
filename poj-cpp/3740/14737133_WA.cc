#include <stdio.h>
#include <string.h>

int N, M;
int mat[20][310];
int tmp[310], sum[20];

int judge(int s)
{
        memset(tmp, 0, sizeof(tmp));
        int cnt = 0;
        for(int i=0; i<N; i++)
                if(s & 1<<i)
                        cnt += sum[i];
        if(cnt!=N) return 0;
        for(int i=0; i<N; i++) {
                if(s & 1<<i) {
                        for(int j=0; j<M; j++) {
                                tmp[j] += mat[i][j];
                                if(tmp[j]>1) return 0;
                        }
                }
        }
        for(int i=0; i<M; i++)
                if(!tmp[i]) return 0;
        return 1;
}

int main()
{
        while(~scanf("%d%d", &N, &M)) {
                memset(sum, 0, sizeof(sum));
                for(int i=0; i<N; i++){
                        for(int j=0; j<M; j++) {
                                scanf("%d", &mat[i][j]);
                                sum[i] += mat[i][j];
                        }
                }
                int s;
                for(s=0; s<1<<N; s++) {
                        if(judge(s)) break;
                }
                if(s<1<<N) printf("Yes, I found it\n");
                else printf("It is impossible\n");
        }

        return 0;
}
