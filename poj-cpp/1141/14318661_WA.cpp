#include <stdio.h>

int main()
{
        int s, b, i;
        char str[128];

        scanf("%s", str);
        s = b = 0;
        for(i=0; str[i]!=0; i++) {
                if(str[i]=='(') s++;
                else if(str[i]==')') s--;
                else if(str[i]=='[') b++;
                else b--;
        }
        for(i=0; str[i]!=0; i++) {
                if(str[i]=='(') {
                        putchar('(');
                        if(s>0) { putchar(')'); s--;}
                } else if(str[i]==')') {
                        if(s<0) { putchar('('); s++;}
                        putchar(')');
                } else if(str[i]=='[') {
                        putchar('[');
                        if(b>0) { putchar(']'); b--;}
                } else {
                        if(b<0) { putchar('['); b++;}
                        putchar(']');
                }
        }

        return 0;
}
