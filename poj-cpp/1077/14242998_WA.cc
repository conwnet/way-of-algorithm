#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pos;

int maps[3][3], vst[3][3], solve[100];

int diry[4] = {1, 0, -1, 0};
int dirx[4] = {0, 1, 0, -1};

int check();

int main()
{
        int i, cnt, ans;
        char str[30];
        queue<Pos> Q;

        gets(str);
        for(i=0, cnt=0; str[i]!='\0'; i++) {
                if(str[i]==' ');
                else if(str[i]!='x') maps[0][cnt++] = str[i]-'0';
                else {
                        maps[0][cnt] = '0';
                        Q.push(Pos(cnt/3, cnt%3));
                        vst[cnt/3][cnt%3] = 1;
                        cnt++;
                }
        }
        ans = -1;
        memset(vst, 0, sizeof(vst));
        while(!Q.empty()) {
                Pos t = Q.front(); Q.pop();
                if(t.first==2 && t.second==2 && check()) { ans = vst[t.first][t.second]; break; }
                for(i=0; i<4; i++) {
                        //if(!vst[t.first+diry[i]][t.second+dirx[i]])
                        if(t.first+diry[i]<3 && t.first+diry[i]>=0)
                        if(t.second+dirx[i]<3 && t.second+dirx[i]>=0) {
                                vst[t.first+diry[i]][t.second+dirx[i]] = vst[t.first][t.second]+1;
                                solve[vst[t.first][t.second]] = i;
                                swap(maps[t.first][t.second], maps[t.first+diry[i]][t.second+dirx[i]]);
                                Q.push(Pos(t.first+diry[i], t.second+dirx[i]));
                                ///printf("test\n");
                        }
                }
        }
        if(ans==-1) printf("unsolvable\n");
        else for(i=1; i<=ans; i++) {
                if(solve[i]==0) printf("d");
                if(solve[i]==1) printf("r");
                if(solve[i]==2) printf("u");
                if(solve[i]==3) printf("l");
        }

        return 0;
}

int check()
{
        for(int i=0; i<8; i++) {
                if(maps[0][i]!=i+1) return 0;
        }
        return 1;
}
