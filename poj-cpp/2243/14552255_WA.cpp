#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

bool vst[10][10];

int dr[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct Pos {
	int r, c, n;
	Pos(int r, int c, int n):
		r(r), c(c), n(n) {}
	Pos() {}
};

int main()
{
	char ss[5], tt[5];
	int sr, sc, tr, tc;
	queue<Pos> que;
	
	while(~scanf("%s%s", ss, tt)) {
		memset(vst, 0, sizeof(vst));
		while(!que.empty()) que.pop();
		que.push(Pos(ss[0], ss[1], 0));
		vst[ss[0]-'a'][ss[1]-'1'] = 1;
		int ans = -1;
		while(!que.empty()) {
			Pos &tmp = que.front();
			que.pop();
			if(tmp.r==tt[0] && tmp.c==tt[1]) {
				ans = tmp.n;
				break;
			}
			for(int i=0; i<8; i++) {
				int y = tmp.r+dr[i];
				int x = tmp.c+dc[i];
				if(vst[y][x]) continue;
				if(y<'a' || y>'h') continue;
				if(x<'1' || x>'8') continue;
				que.push(Pos(y, x, tmp.n+1));
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", ss, tt, ans);
	}

	return 0;
}

