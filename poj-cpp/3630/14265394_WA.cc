#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nTree {
        nTree *num[10];
        int mark;
}nt[100001];

int main()
{
        int T, i, n, j, update, cnt;
        char str[15];

        scanf("%d", &T);
        while(T--) {
                memset(nt, 0, sizeof(nt));
                cnt = 0;
                scanf("%d", &n);
                for(i=0; i<n; i++) {
                        scanf("%s", str);
                        nTree* t = nt;
                        update = 0;
                        for(j=0; str[j]!='\0'; j++) {
                                if(!t->num[str[j]-'0']) {
                                        t->num[str[j]-'0'] = &nt[cnt++];
                                        update = 1;
                                }
                                if(t->mark==1) { update = 0; break; }
                                t = t->num[str[j]-'0'];
                        }
                        t->mark = 1;
                        if(!update) for(i++; i<n; i++) scanf("%d", &j);
                }
                if(update) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
