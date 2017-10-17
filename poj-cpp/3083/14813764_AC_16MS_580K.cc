#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

char maps[50][50];
int N, M, tr, tc;
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };

int ldfs(int r, int c, int dir, int h)
{
        if(r==tr && c==tc) return h;
        for(int i=0; i<4; i++) {
                int d = (dir-1+i+4) % 4;
                int y = r + dr[d];;
                int x = c + dc[d];
                if(maps[y][x]=='.') {
                        return ldfs(y, x, d, h+1);
                }
        }
}

int rdfs(int r, int c, int dir, int h)
{
        if(r==tr && c==tc) return h;
        for(int i=4; i>0; i--) {
                int d = (dir-3+i+4) % 4;
                int y = r + dr[d];;
                int x = c + dc[d];
                if(maps[y][x]=='.') {
                        return rdfs(y, x, d, h+1);
                }
        }
}

struct Pos {
        int y, x, t;
        Pos(int a, int b, int c):
                y(a), x(b), t(c) {}
        Pos() {}
};
int vst[50][50];

int main()
{
        int T, sr, sc;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &M, &N);
                for(int i=1; i<=N; i++)
                        scanf("%s", maps[i]+1);
                for(int i=1; i<=N; i++) {
                        for(int j=1; j<=M; j++) {
                                if(maps[i][j]=='S') {
                                        sr = i; sc = j; maps[i][j] = '.';
                                }
                                else if(maps[i][j]=='E') {
                                        tr = i; tc = j; maps[i][j] = '.';
                                }
                        }
                }
                int ll = ldfs(sr, sc, 0, 1);
                int rr = rdfs(sr, sc, 0, 1);
                queue<Pos> que;
                memset(vst, 0, sizeof(vst));
                que.push(Pos(sr, sc, 1));
                vst[sr][sc] = 1;
                int ans = 0;
                while(!que.empty()) {
                        Pos tmp = que.front(); que.pop();
                        if(tmp.y==tr && tmp.x==tc) {
                                ans = tmp.t; break;
                        }
                        for(int i=0; i<4; i++) {
                                int y = tmp.y+dr[i];
                                int x = tmp.x+dc[i];
                                if(vst[y][x] || maps[y][x]!='.')
                                        continue;
                                vst[y][x] = 1;
                                que.push(Pos(y, x, tmp.t+1));
                        }
                }
                printf("%d %d %d\n", ll, rr, ans);
        }

        return 0;
}
