#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 150005;

int trie[maxn][26];
int wcnt[maxn];
int scnt, cnt;
char str[1002][25];


void add_word(char *str)
{
        int t = 0;
        for(int i=0; str[i]; i++) {
                int idx = str[i]-'a';
                if(!trie[t][idx])
                        trie[t][idx] = cnt++;
                t = trie[t][idx];
                wcnt[t]++;

        }
}

void print(char *str)
{
        int t = 0;
        for(int i=0; str[i]; i++) {
                int idx = str[i]-'a';
                t = trie[t][idx];
                putchar(str[i]);
                if(wcnt[t]==1)
                        break;
        }
}

int main()
{
        scnt = 0;
        cnt = 1;
        memset(wcnt, 0, sizeof(wcnt));
        memset(trie, 0, sizeof(trie));
        while(gets(str[scnt])) {
                if(str[scnt][0]=='~') break;
                add_word(str[scnt]);
                scnt++;
        }
        for(int i=0; i<scnt; i++) {
                printf("%s ", str[i]);
                print(str[i]);
                putchar('\n');
        }

        return 0;
}
