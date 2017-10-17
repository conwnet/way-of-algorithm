#include <stdio.h>
#include <string.h>

int trie[1000000][2], tc, val[1000000];

int add_str(char *str)
{
        int p = 0, update = 0, mark = 0;
        for(int i=0; str[i]; i++) {
                int idx = str[i]-'0';
                if(!trie[p][idx]) {
                        trie[p][idx] = ++tc;
                        update = 1;
                }
                p = trie[p][idx];
                if(val[p]) mark = 1;
        }
        val[p] = 1;
        if(mark) return 1;
        if(!update) return 1;
        return 0;
}

int main()
{
        char str[128];
        int nC = 1;
        tc = 0;
        int faild = 0;
        while(~scanf("%s", str)) {
                if(str[0]=='9') {
                        if(!faild) printf("Set %d is immediately decodable\n", nC);
                        else printf("Set %d is not immediately decodable\n", nC);
                        nC++;
                        memset(trie, 0, sizeof(trie));
                        tc++;
                        faild = 0;
                        continue;
                }
                if(faild) continue;
                faild = add_str(str);
        }

        return 0;
}



