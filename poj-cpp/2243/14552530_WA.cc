#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int vst[10][10];

int dr[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dc[8] = {2, -2, 2, -2, 1, -1, 1, -1};

struct Pos {
	int r, c;
	Pos(int r, int c):
		r(r), c(c) {}
	Pos() {}
};

queue<Pos> que;

int main()
{
	char ss[5], tt[5];
	
	while(~scanf("%s%s", ss, tt)) {
		memset(vst, -1, sizeof(vst));
		while(!que.empty()) que.pop();
		que.push(Pos(ss[0], ss[1]));
		vst[ss[0]-'a'][ss[1]-'1'] = 0;
		while(!que.empty()) {
			Pos &tmp = que.front();
			que.pop();
			if(tmp.r==tt[0] && tmp.c==tt[1]) {
				break;
			}
			for(int i=0; i<8; i++) {
				int y = tmp.r+dr[i];
				int x = tmp.c+dc[i];
				if(y<'a' || y>'h') continue;
				if(x<'1' || x>'8') continue;
				if(vst[y-'a'][x-'1']>=0) continue;
				vst[y-'a'][x-'1'] = vst[tmp.r-'a'][tmp.c-'1']+1;
				que.push(Pos(y, x));
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", ss, tt, vst[tt[0]-'a'][tt[1]-'1']);
	}

	return 0;
}
