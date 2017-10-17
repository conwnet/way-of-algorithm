#include <stdio.h>

int coin[1024], N, M, res[128][1024];

int judge1(int n)
{
        for(int i=0; i<M; i++) {
                int found = 0;
                for(int j=1; j<=res[i][0]; j++) {
                        if(res[i][j]==n) {
                                if(res[i][1001]!=1) return 0;
                                found = 1;
                                break;
                        }
                }
                if(found) continue;
                for(int j=res[i][0]+1; j<=2*res[i][0]; j++) {
                        if(res[i][j]==n) {
                                if(res[i][1001]!=-1) return 0;
                                found = 1;
                                break;
                        }
                }
                if(found) continue;
                if(res[i][1001]) return 0;
        }
        return 1;
}

int judge2(int n)
{
        for(int i=0; i<M; i++) {
                int found = 0;
                for(int j=1; j<=res[i][0]; j++) {
                        if(res[i][j]==n) {
                                if(res[i][1001]!=-1) return 0;
                                found = 1;
                                break;
                        }
                }
                if(found) continue;
                for(int j=res[i][0]+1; j<=2*res[i][0]; j++) {
                        if(res[i][j]==n) {
                                if(res[i][1001]!=1) return 0;
                                found = 1;
                                break;
                        }
                }
                if(found) continue;
                if(res[i][1001]) return 0;
        }
        return 1;
}

int main()
{
        char ss[5];
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++) {
                scanf("%d", &res[i][0]);
                for(int j=1; j<=res[i][0]*2; j++)
                        scanf("%d", &res[i][j]);
                scanf("%s", ss);
                if('<'==ss[0]) res[i][1001] = 1;
                else if('>'==ss[0]) res[i][1001] = -1;
                else res[i][1001] = 0;
        }
        int cnt = 0, ans;
        for(int i=1; i<=N; i++) {
                if(judge1(i) || judge2(i)) {
                        cnt++;
                        ans = i;
                }
        }
        if(cnt==1) printf("%d\n", ans);
        else printf("%d\n", 0);

        return 0;
}
