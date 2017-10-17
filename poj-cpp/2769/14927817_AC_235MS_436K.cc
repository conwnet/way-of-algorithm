#include <stdio.h>
#include <string.h>

int vst[100000], num[400], N, i;

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
        memset(vst, 0, 4*n);
        for(i=0; i<N; i++) {
                if(!vst[num[i]%n]) vst[num[i]%n] = 1;
                else return 0;
        }
        return 1;
}

int main()
{
        int T, a;
        T = getint();
        while(T--) {
                N = getint();
                for(i=0; i<N; i++)
                        num[i] = getint();
                for(a=N; ; a++) {
                        if(modul(a)) break;
                }
                printf("%d\n", a);
        }

        return 0;
}
