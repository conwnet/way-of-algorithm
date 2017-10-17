#include <stdio.h>
#include <string.h>

int cont;

struct ADT{
        int cnt;
        ADT *next[26];
        ADT() {
                cnt = 0;
                memset(next, 0, sizeof(next));
        }
}Trie;

void insert(char *str);
void dfs(ADT *Trie);

int main()
{
        int i;
        char str[50];

        while(~scanf("%s", str)) {
                if(str[0]=='.') break;
                insert(str);
        }
        cont = 0;
        dfs(&Trie);

        if(cont>2) printf("Impossible\n");
        else printf("Possible\n");

        return 0;
}

void insert(char *str)
{
        ADT *t = &Trie;
        for(int i=0; str[i]!='\0'; i++) {
                if(t->next[str[i]-'a']==0) t->next[str[i]-'a'] = new(ADT);
                t = t->next[str[i]-'a'];
        }
        t->cnt++;
}

void dfs(ADT *t)
{
        int flag = 0;
        for(int i=0; i<26; i++) {
                if(t->next[i]!=0) {
                        flag = 1;
                        dfs(t->next[i]);
                }
        }
        if(!flag) if(t->cnt%2) cont++;
}
