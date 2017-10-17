#include <stdio.h>

int main()
{
        int top, s, b;
        char stk[128], c;

        top = s = b = 0;
        while((c=getchar())!='\n') {
                if(c=='(') { putchar(c); s++; stk[++top] = c; }
                else if(c=='[') { putchar(c); b++; stk[++top] = c; }
                else if(c==')') {
                        while(s && top>0 && stk[top]=='[') {
                                putchar(']');
                                top--;
                        }
                        if(stk[top]=='(') { putchar(c); top--; s--;}
                        else printf("()");
                } else if(c==']') {
                        while(b && top>0 && stk[top]=='(') {
                                putchar(')');
                                top--;
                        }
                        if(stk[top]=='[') { putchar(c); top--; b--; }
                        else printf("[]");
                } else putchar(c);
        }
        while(top>0) {
                if(stk[top]=='(') putchar(')');
                else putchar(']');
                top--;
        }

        return 0;
}
