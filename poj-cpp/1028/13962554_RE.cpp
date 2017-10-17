#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct T{
        char web[100];
        struct T *next;
        struct T *prev;
};


int main()
{
        T *p, *now;
        char Cmd[20];

        now = p = (T *)malloc(sizeof(T));
        p->next = NULL;
        strcpy(p->web, "http://www.acm.org/");
        while(scanf("%s", Cmd)){
                if(Cmd[0]=='Q') break;
                if(Cmd[0]=='V'){
                        p = (T *)malloc(sizeof(T));
                        p->next = NULL;
                        scanf("%s", p->web);
                        now->next = p;
                        p->prev = now;
                        now = now->next;
                        printf("%s\n", now->web);
                } else if(Cmd[0]=='B') {
                        if(now->prev==NULL){
                                printf("Ignored\n");
                                continue;
                        }
                        now = now->prev;
                        printf("%s\n", now->web);
                } else {
                        if(now->next==NULL){
                                printf("Ignored\n");
                                continue;
                        }
                        now = now->next;
                        printf("%s\n", now->web);
                }
        }



        return 0;
}
