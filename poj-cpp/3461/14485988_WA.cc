#include <stdio.h>
#include <string.h>

int f[20000];
char P[20000], T[1500000];

int kmp(char *T, char *P);
void getf(char *P, int *f);

int main()
{
        int nCase;

        scanf("%d", &nCase);
        while(nCase--) {
                scanf("%s%s", P, T);
                printf("%d\n", kmp(T, P));
        }

        return 0;
}

int kmp(char *T, char *P)
{
        int tl = strlen(T);
        int pl = strlen(P), cnt = 0;

        getf(P, f);
        int j = 0;
        for(int i=0; i<tl; i++) {
                while(j && P[j]!=T[i]) j = f[j];
                if(P[j]==T[i]) j++;
                if(j==pl) { cnt++; j = f[j+1]; }
        }

        return cnt;
}

void getf(char *P, int *f)
{
        int pl = strlen(P);
        f[0] = f[1] = 0;
        for(int i=1; i<pl; i++) {
                int j = f[i];
                while(j && P[i]!=P[j]) j = f[j];
                f[i+1] = P[i]==P[j] ? j+1 : 0;
        }
}
