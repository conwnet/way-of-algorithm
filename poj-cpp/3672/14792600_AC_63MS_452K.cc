#include <stdio.h>

char path[100005];
int M, T, F, D, U;

int is_ok(int m)
{
        int res = M;
        for(int i=0; i<m; i++) {
                if(path[i]=='u') res -= U;
                else if(path[i]=='f') res -= F;
                else res -= D;
                if(res < 0) return 0;
        }
        for(int i=m-1; i>=0; i--) {
                if(path[i]=='u') res -= D;
                else if(path[i]=='f') res -= F;
                else res -= U;
                if(res < 0) return 0;
        }
        return 1;
}

int main()
{
        scanf("%d%d%d%d%d", &M, &T, &U, &F, &D);
        for(int i=0; i<T; i++) {
                getchar();
                path[i] = getchar();
        }
        int l = 0, r = T;
        while(l<r) {
                int m = (l+r+1)>>1;
                if(is_ok(m)) l = m;
                else r = m-1;
        }
        printf("%d\n", l);

        return 0;
}
