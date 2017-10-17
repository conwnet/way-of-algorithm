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
        int i, j, l;
        char c, word[500];

        while(1){
                scanf("%s", word);
                if(!strcmp(word, "ENDOFINPUT"))break;
                if(!strcmp(word, "START"));

                scanf("%s", word);
                if(!strcmp(word, "END")) break;
                l = strlen(word);
                for(i=0; i<l; i++){
                        if(isalpha(word[i]))
                                word[i] = change(word[i]);
                }
                printf("%s", word);


                while(scanf("%s", word)){
                        if(!strcmp(word, "END")) break;
                        l = strlen(word);
                        for(i=0; i<l; i++){
                                if(isalpha(word[i]))
                                        word[i] = change(word[i]);
                        }
                        printf(" %s", word);
                }
                printf("\n");
        }

        return 0;
}
