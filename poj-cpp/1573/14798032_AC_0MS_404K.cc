#include <stdio.h>
#include <string.h>

int maps[11][11], R, C, S, vst[11][11];

int main()
{
        for(;;) {
                scanf("%d%d%d", &R, &C, &S);
                if(!R && !C && !S) break;
                for(int i=0; i<R; i++) {
                        getchar();
                        for(int j=0; j<C; j++)
                                maps[i][j] = getchar();
                }
                memset(vst, 0, sizeof(vst));
                int sr = 0, sc = S-1, loop = 0, step=0;
                while(sr>=0 && sr<R && sc>=0 && sc<C) {
                        if(!vst[sr][sc]) vst[sr][sc] = ++step;
                        else { loop = 1; break; }
                        switch(maps[sr][sc]) {
                                case 'N': sr--; break;
                                case 'E': sc++; break;
                                case 'S': sr++; break;
                                case 'W': sc--; break;
                        }
                }
                if(loop) printf("%d step(s) before a loop of %d step(s)\n",
                        vst[sr][sc]-1, step-vst[sr][sc]+1);
                else printf("%d step(s) to exit\n", step);
        }

        return 0;
}
