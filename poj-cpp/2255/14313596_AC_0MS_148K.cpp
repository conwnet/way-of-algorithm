#include <stdio.h>
#include <string.h>

int preo[30], ino[30], ln[30], rn[30], cnt;

int create(int, int);
void print(int);

int main()
{
        char pstr[30], istr[30];
        int i, j;

        while(~scanf("%s%s", pstr, istr)) {
                memset(ln, 0, sizeof(ln));
                memset(rn, 0, sizeof(rn));
                for(i=0; pstr[i]!='\0'; i++) {
                        preo[i] = pstr[i]-'A'+1;
                }
                for(i=0; istr[i]!='\0'; i++) {
                        ino[i] = istr[i]-'A'+1;
                }
                cnt = 0;
                create(0, i-1);
                for(i=0; preo[0]!=ino[i]; i++);
                print(ino[i]);
                printf("\n");
        }

        return 0;
}

int create(int s, int e)
{
        int i, j;
        for(i=s; i<=e; i++)
                if(preo[cnt]==ino[i]) { cnt++; break; }
        if(s<i) ln[ino[i]] = create(s, i-1);
        if(i<e) rn[ino[i]] = create(i+1, e);

        return ino[i];
}

void print(int r)
{
        if(ln[r]) print(ln[r]);
        if(rn[r]) print(rn[r]);
        printf("%c", r+'A'-1);
}
