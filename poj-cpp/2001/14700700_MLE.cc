#include <stdio.h>
#include <string.h>

const int maxn = 300005;

int trie[maxn][26];
int wcnt[maxn][26];
int cnt;
char word[25];
char str[1001][21], scnt;

void add_word(char *str)
{
        int t = 0;
        for(int i=0; str[i]; i++) {
                int idx = str[i]-'a';
                if(!trie[t][idx])
                        trie[t][idx] = cnt++;
                wcnt[t][idx]++;
                t = trie[t][idx];
        }
}

void print(char *str)
{
        int t = 0;
        for(int i=0; str[i]; i++) {
                int idx = str[i]-'a';
                putchar(str[i]);
                if(wcnt[t][idx]==1)
                        break;
                t = trie[t][idx];
        }
}

int main()
{
        cnt = 1;
        scnt = 0;

        memset(wcnt, 0, sizeof(wcnt));
        memset(trie, 0, sizeof(trie));
        while(~scanf("%s", str[scnt])) {
                if(str[scnt][0]=='~') break;
                add_word(str[scnt++]);
        }
        for(int i=0; i<scnt; i++) {
                printf("%s ", str[i]);
                print(str[i]);
                putchar('\n');
        }

        return 0;
}


/**<

test p

 */
