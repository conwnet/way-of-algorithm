#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
        int id;
        struct Node *next[26];
}TRIE;

TRIE Trie;
int color_cnt, stk_cnt, color[250010], p[250010];

int get_n(char *str);
void init_node(TRIE* t);
int findp(int u);

int main()
{
        char str1[64], str2[64];
        int i, u, v, cnt;

        color_cnt = 1;
        stk_cnt = 0;
        init_node(&Trie);
        memset(color, 0, sizeof(color));
        for(i=0; i<250010; i++) p[i] = i;
        while(~scanf("%s%s", str1, str2)) {
                u = findp(get_n(str1));
                v = findp(get_n(str2));
                if(u!=v) p[u] = v;
        }
        for(i=1, cnt=0; i<color_cnt; i++) {
                if(p[i]==i) cnt++;
        }
        if(cnt>1) {
                printf("Impossible\n");
                return 0;
        }
        for(i=1, cnt=0; i<color_cnt; i++) {
                if(color[i]%2) cnt++;
        }
        if(cnt>2) printf("Impossible\n");
        else printf("Possible\n");


        return 0;
}

void init_node(TRIE* t)
{
        memset(t, 0, sizeof(TRIE));
}

int get_n(char *str)
{
        TRIE *t = &Trie;
        int i, nc;

        for(i=0; str[i]!='\0'; i++) {
                nc = str[i]-'a';
                if(t->next[nc]==0) {
                        t->next[nc] = (TRIE*)malloc(sizeof(TRIE));
                        init_node(t->next[nc]);
                }
                t = t->next[nc];
        }
        if(!t->id){
                t->id = color_cnt++;
        }
        color[t->id]++;
        return t->id;
}

int findp(int u)
{
        if(p[u]==u) return u;
        else return p[u] = findp(p[u]);
}
