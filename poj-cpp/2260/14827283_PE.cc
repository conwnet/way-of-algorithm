#include <stdio.h>
#include <string.h>

int mat[128][128], N, row[128], col[128];

int main()
{
        while(scanf("%d", &N) && N) {
                memset(row, 0, sizeof(row));
                memset(col, 0, sizeof(col));
                for(int i=0; i<N; i++) {
                        for(int j=0; j<N; j++) {
                                scanf("%d", &mat[i][j]);
                                row[i] += mat[i][j];
                                col[j] += mat[i][j];
                        }
                }
                int rcnt = 0, ccnt = 0, y, x;
                for(int i=0; i<N; i++) {
                        if(row[i]&1) { rcnt++; y = i+1; }
                        if(col[i]&1) { ccnt++; x = i+1; }
                }
                if(rcnt+ccnt==0) printf("OK\n");
                else if(rcnt>1 || ccnt>1) printf("Corrupt\n");
                else printf("Change bit (%d, %d)\n", y, x);
        }

        return 0;
}
