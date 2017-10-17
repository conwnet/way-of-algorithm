#include <stdio.h>
#include <string.h>
#include <ctype.h>

char change(char c)
{
        char t = c-5;
        if(t<'A') t += 26;
        return t;
}

int main()
{
        int i, j, flag, l;
        char c, word[500];

        while(1){
                scanf("%s", word);
                if(!strcmp(word, "ENDOFINPUT"))break;
                if(!strcmp(word, "START"));

                scanf("%s", word);
                if(!strcmp(word, "END")) break;
                flag = 0;
                l = strlen(word);
                if(!isalpha(word[l-1])){
                        flag = 1;
                        c = word[l-1];
                        word[l-1] = '\0';
                        l--;
                }
                for(i=0; i<l; i++){
                        word[i] = change(word[i]);
                }
                printf("%s", word);
                if(flag) printf("%c", c);


                while(scanf("%s", word)){
                        if(!strcmp(word, "END")) break;
                        flag = 0;
                        l = strlen(word);
                        if(!isalpha(word[l-1])){
                                flag = 1;
                                c = word[l-1];
                                word[l-1] = '\0';
                                l--;
                        }
                        for(i=0; i<l; i++){
                                word[i] = change(word[i]);
                        }
                        printf(" %s", word);
                        if(flag) printf("%c", c);
                }
                printf("\n");
        }

        return 0;
}
