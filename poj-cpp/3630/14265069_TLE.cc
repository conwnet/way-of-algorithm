
#include <stdio.h>
#include <string.h>

struct nTree {
        nTree *num[10];
        int mark;
        nTree(){ memset(num, 0, sizeof(num)); mark = 0; }
}nt;

int main()
{
        int T, i, n, j, update;
        char str[15];

        scanf("%d", &T);
        while(T--) {
                memset(nt.num, 0, sizeof(nt.num));
                scanf("%d", &n);
                for(i=0; i<n; i++) {
                        scanf("%s", str);
                        nTree* t = &nt;
                        update = 0;
                        for(j=0; str[j]!='\0'; j++) {
                                if(!t->num[str[j]-'0']) {
                                        t->num[str[j]-'0'] = new nTree;
                                        update = 1;
                                }
                                if(t->mark==1) { update = 0; break; }
                                t = t->num[str[j]-'0'];
                        }
                        t->mark = 1;
                        if(!update) for(i++; i<n; i++) scanf("%s", str);
                }
                if(update) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
