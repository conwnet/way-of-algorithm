#include <stdio.h>

int main()
{
        char ch;

        while((ch=getchar()) != '#') {
                if(ch==' ') printf("%%20");
                else if(ch=='!') printf("%%21");
                else if(ch=='$') printf("%%24");
                else if(ch=='%') printf("%%25");
                else if(ch=='(') printf("%%28");
                else if(ch==')') printf("%%29");
                else if(ch=='*') printf("%%2a");
                else putchar(ch);
        }

        return 0;
}
