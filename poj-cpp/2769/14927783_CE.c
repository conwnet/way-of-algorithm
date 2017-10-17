#include <stdio.h>
#include <string.h>

const int maxn = 1e6;
int vst[maxn], num[400], N;

int getint()
{
        int ch, ret;
        while(ch=getchar())
                if(ch<='9' && ch>='0') break;
        ret = ch-'0';
        while(ch=getchar()) {
                if(ch<'0' || ch>'9') break;
                ret = ret*10 + ch-'0';
        }
        return ret;
}

int modul(int n)
{
        memset(vst, 0, sizeof(vst));
        for(int i=0; i<N; i++) {
                if(!vst[num[i]%n]) vst[num[i]%n] = 1;
                else return 0;
        }
        return 1;
}

int main()
{
        int i, T;
        T = getint();
        while(T--) {
                N = getint();
                for(i=0; i<N; i++)
                        num[i] = getint();
                for(i=N; ; i++)
                        if(modul(i)) break;
                printf("%d\n", i);
        }

        return 0;
}
