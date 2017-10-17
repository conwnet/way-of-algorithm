#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> Pos;

int maps[5][5];
Pos fath[5][5];
int vst[5][5];
int dr[4] = {0, -1, 1, 0};
int dc[4] = {1, 0, 0, -1};

void bfs()
{
        queue<Pos> que;
        memset(vst, 0, sizeof(vst));
        que.push(Pos(0, 0));
        vst[0][0] = 1;
        while(!que.empty()) {
                Pos tmp = que.front();
                que.pop();
                if(tmp.first==4 && tmp.second==4) break;
                for(int i=0; i<4; i++) {
                        int r = tmp.first+dr[i];
                        int c = tmp.second+dc[i];
                        if(!maps[r][c] && !vst[r][c] && r>=0 && r<5 && c>=0 && c<5) {
                                fath[r][c] = tmp;
                                vst[r][c] = 1;
                                que.push(Pos(r, c));
                        }
                }
        }
}

void print(int r, int c)
{
        if(r!=0 || c!=0)
                print(fath[r][c].first, fath[r][c].second);
        printf("(%d, %d)\n", r, c);
}

int main()
{
        for(int i=0; i<5; i++)
                for(int j=0; j<5; j++)
                        scanf("%d", &maps[i][j]);
        bfs();
        print(4, 4);

        return 0;
}
