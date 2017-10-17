#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos {
	int l, r, c;
	Pos(int l, int r, int c):
		l(l), r(r), c(c) {}
	Pos() {}
};

int L, R, C;
char maps[35][35][35];
int vst[35][35][35];
int dl[6] = {1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, 0, 0, 1, -1};
int dc[6] = {0, 0, 1, -1, 0, 0};
queue<Pos> que;

int main()
{
	while(scanf("%d%d%d", &L, &R, &C)) {
		if(!L && !R && !C) break;
		while(!que.empty()) que.pop();
		memset(maps, 0, sizeof(maps));
		memset(vst, -1, sizeof(vst));
		for(int i=1; i<=L; i++) {
			for(int j=1; j<=R; j++) {
				scanf("%s", maps[i][j]+1);
			}
		}
		int sl, sr, sc, el, er, ec;
		for(int i=1; i<=L; i++)
			for(int j=1; j<=R; j++)
				for(int k=1; k<=C; k++)
					if(maps[i][j][k]=='S') {
						sl = i;
						sr = j;
						sc = k;
					} else if(maps[i][j][k]=='E') {
						el = i;
						er = j;
						ec = k;
					}
		vst[sl][sr][sc] = 0;
		que.push(Pos(sl, sr, sc));
		while(!que.empty()) {
			Pos tmp = que.front(); que.pop();
			if(tmp.l==el && tmp.r==er && tmp.c==ec)
				break;
			for(int i=0; i<6; i++) {
				int z = tmp.l + dl[i];
				int y = tmp.r + dr[i];
				int x = tmp.c + dc[i];
				if(maps[z][y][x]=='#') continue;
				if(!maps[z][y][x]) continue;
				if(vst[z][y][x]!=-1) continue;
				vst[z][y][x] = vst[tmp.l][tmp.r][tmp.c] + 1;
				que.push(Pos(z, y, x));
			}
		}
		int ans = vst[el][er][ec];
		if(ans!=-1)
			printf("Escaped in %d minute(s).\n", ans);
		else printf("Trapped!\n");
	}

	return 0;
}



