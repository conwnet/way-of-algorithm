#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int maps[30][30], cnt[30];
int N, r[30], color[30];

int cmp(int a, int b)
{
        return cnt[a] > cnt[b];
}

int main()
{
        char mstr[30];
        int vst[30];
        while(scanf("%d", &N) && N) {
                memset(maps, 0, sizeof(maps));
                for(int i=0; i<N; i++) {
                        scanf("%s", mstr);
                        int j;
                        for(j=2; mstr[j]; j++)
                                maps[i][mstr[j]-'A'] = 1;
                        cnt[i] = j;
                }
                for(int i=0; i<30; i++) r[i] = i;
                sort(r, r+N, cmp);
                int cnt = 0;
                memset(color, 0, sizeof(color));
                for(int i=0; i<N; i++) {
                        int t = r[i];
                        if(color[t]) continue;
                        color[t] = ++cnt;
                        while(1) {
                                int ok = 0;
                                for(int j=0; j<N; j++) {
                                        if(color[j]) continue;
                                        int k;
                                        for(k=0; k<N; k++) {
                                                if(maps[j][k] && color[k]==cnt)
                                                        break;
                                        }
                                        if(k==N) { color[j] = cnt; ok = 1; };
                                }
                                if(!ok) break;
                        }

                }
                printf("%d %s needed.\n", cnt, cnt==1?"channel":"channels");
        }

        return 0;
}

