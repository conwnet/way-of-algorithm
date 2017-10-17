#include <stdio.h>
#include <string.h>

int bi[102][1010];
int len[102];

void add(int *a, int la, int *b, int *lb)
{
        for(int i=0; i<la; i++) {
                b[i] += a[i];
        }
        if(la>*lb) *lb = la;
        for(int i=0; i<*lb; i++) {
                if(b[i]>=100000) {
                        b[i+1] += b[i]/100000;
                        b[i] %= 100000;
                }
        }
        if(b[*lb]) (*lb)++;
}

void print(int *a, int l)
{
        printf("%d", a[l-1]);
        for(int i=l-2; i>=0; i--)
                printf("%05d", a[i]);
        printf("\n", l);
}

int main()
{
        int a, b, c;
        while(~scanf("%d%d%d", &a, &b, &c)) {
                memset(bi, 0, sizeof(bi));
                memset(len, 0, sizeof(len));
                bi[1][0] = a; len[1] = 1;
                bi[2][0] = b; len[2] = 1;
                bi[3][0] = c; len[3] = 1;
                for(int i=4; i<=100; i++) {
                        add(bi[i-3], len[i-3], bi[i], &len[i]);
                        add(bi[i-2], len[i-2], bi[i], &len[i]);
                        add(bi[i-1], len[i-1], bi[i], &len[i]);
                        ///print(bi[i], len[i]);
                }
                print(bi[100], len[100]);
        }

        return 0;
}

