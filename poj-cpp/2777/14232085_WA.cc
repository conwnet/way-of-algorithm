#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

struct Cmd{
        int s;
        int l, r, n;
}cmd[50];

int vst[110000], L, T, O, c_cnt, bod[110000];

int main()
{
        char c[5];
        int i, j, l, r, n, cnt, ans;
        map<int, int> mp;

        scanf("%d%d%d", &L, &T, &O);
        memset(vst, 0, sizeof(vst));
        c_cnt = 0;
        for(i=0; i<O; i++) {
                scanf("%s", c);
                if(c[0]=='C') {
                        scanf("%d%d%d", &l, &r, &n);
                        vst[l] = vst[r] = 1;
                        cmd[c_cnt].s = 0;
                        cmd[c_cnt].l = l;
                        cmd[c_cnt].r = r;
                        cmd[c_cnt++].n = n;
                } else {
                        scanf("%d%d", &l, &r);
                        cmd[c_cnt].s = 1;
                        cmd[c_cnt].l = l;
                        cmd[c_cnt++].r = r;
                }
        }
        cnt = 1;
        for(i=1; i<=L; i++) {
                if(vst[i]) mp[i] = cnt++;
        }
        for(i=0; i<c_cnt; i++) {
                cmd[i].l = mp[cmd[i].l];
                cmd[i].r = mp[cmd[i].r];
        }
        for(i=1; i<=cnt; i++) {
                bod[i] = 1;
        }
        for(i=0; i<c_cnt; i++) {
                if(cmd[i].s==0) {
                        for(j=cmd[i].l; j<=cmd[i].r; j++)
                                bod[j] = cmd[i].n;
                } else {
                        ans = 0;
                        memset(vst, 0, sizeof(vst));
                        for(j=cmd[i].l; j<=cmd[i].r; j++) {
                                if(!vst[bod[j]]) ans++;
                                vst[bod[j]] = 1;
                        }
                        printf("%d\n", ans);
                }
        }


        return 0;
}




