#include <stdio.h>
#include <string.h>

struct Kid {
        char name[30];
        int next;
};

Kid kid[80];

int main()
{
        int N, w, s;

        scanf("%d", &N);
        for(int i=1; i<=N; i++) {
                scanf("%s", kid[i].name);
                kid[i].next = i+1;
        }
        kid[0].next = 1;
        kid[N].next = 1;
        scanf("%d,%d", &w, &s);
        int p = w-1;
        while(N--) {
                for(int i=1; i<s; i++)
                        p = kid[p].next;
                printf("%s\n", kid[kid[p].next].name);
                kid[p].next = kid[kid[p].next].next;
        }

        return 0;
}

