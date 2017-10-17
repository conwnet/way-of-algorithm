#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char maps[30][30];
int N;

int main()
{
        char ch, r, c, ok;

        while(scanf("%d", &N) && N) {
                memset(maps, 0, sizeof(maps));
                getchar();
                r = c = ok = 0;
                while((ch=getchar())!='\n') {
                        maps[r][ok?c--:c++] = ch;
                        if(c==N || c==-1) {
                                ok = !ok;
                                r++;
                                c==N ? c-- : c++;
                        }
                }
                for(int i=0; maps[0][i]; i++) {
                        int r = 0;
                        while(maps[r][i]) {
                                putchar(maps[r][i]);
                                r++;
                        }
                }
                putchar('\n');
        }

        return 0;
}
