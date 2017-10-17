#include <stdio.h>
#include <string.h>

const int N = 1000;
int c[N][N], row, col;

int lowbit(int n)
{
        return n&(-n);
}

int Sum(int i, int j)
{
        int tempj, sum=0;
        while(i>0) {
                tempj = j;
                while(tempj>0) {
                        sum += c[i][tempj];
                        tempj -= lowbit(tempj);
                }
                i -= lowbit(i);
        }
        return sum;
}

void Update(int i, int j, int num)
{
        int tempj;
        while(i<=row) {
                tempj = j;
                while(tempj<=col) {
                        c[i][tempj] += num;
                        tempj += lowbit(tempj);
                }
                i += lowbit(i);
        }
}

int main()
{
        int op, a, b, n, sa, sb;

        scanf("%d%d", &op, &col);
        row = col;
        memset(c, 0, sizeof(c));
        while(scanf("%d", &op) && op!=3) {
                if(op==1) {
                        scanf("%d%d%d", &a, &b, &n);
                        a++; b++;
                        Update(a, b, n);
                } else if(op==2) {
                        scanf("%d%d%d%d", &sa, &sb, &a, &b);
                        a++; b++;
                        printf("%d\n", Sum(a, b)-Sum(a, sb)-Sum(sa, b)+Sum(sa, sb));
                }
        }

        return 0;
}

