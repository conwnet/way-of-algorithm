#include <stdio.h>
#include <string.h>

int fa[400005];
char str[400005];

void get_f(int l)
{
        fa[0] = fa[1] = 0;
        for(int i=1; i<l; i++) {
                int j = fa[i];
                while(j && str[i]!=str[j])
                        j = fa[j];
                fa[i+1] = (str[i]==str[j] ? j+1 : 0);
        }
}

void print(int n)
{
        if(fa[n])
                print(fa[n]);
        printf("%d ", n);
}

int main()
{
        while(~scanf("%s", str)) {
                int l = strlen(str);
                get_f(l);
                print(fa[l]);
                printf("%d\n", l);
        }

        return 0;
}
