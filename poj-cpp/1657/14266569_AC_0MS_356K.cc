#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int sx, sy, tx, ty;

int search1();
int search2();
int search3();
int search4();

int main()
{
        int T;
        char str[5];

        scanf("%d", &T);
        while(T--) {
                scanf("%s", str);
                sx = str[0]-'a';
                sy = str[1]-'1';
                scanf("%s", str);
                tx = str[0]-'a';
                ty = str[1]-'1';
                printf("%d %d %d ", search1(), search2(), search3());
                if(search4()==-1) printf("Inf\n");
                else printf("%d\n", search4());
        }

        return 0;
}

int search1()
{
        if(sx==tx && sy==ty) return 0;
        return max(abs(tx-sx), abs(ty-sy));
}

int search2()
{
        if(sx==tx && sy==ty) return 0;
        if(sx+sy==tx+ty || sx-sy==tx-ty) return 1;
        if(sx==tx || sy==ty) return 1;
        return 2;
}

int search3()
{
        if(sx==tx && sy==ty) return 0;
        if(sx==tx || sy==ty) return 1;
        return 2;
}

int search4()
{
        if(sx==tx && sy==ty) return 0;
        if((abs(tx-sx)+abs(ty-sy))&1) return -1;
        if(sx+sy==tx+ty || sx-sy==tx-ty) return 1;
        return 2;
}
