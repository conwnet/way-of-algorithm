#include <stdio.h>
#include <algorithm>

using namespace std;

int clk[9];

void Move(int op)
{
        switch(op) {
                case 1: clk[0]++; clk[1]++; clk[3]++; clk[4]++; break;
                case 2: clk[0]++; clk[1]++; clk[2]++; break;
                case 3: clk[1]++; clk[2]++; clk[4]++; clk[5]++; break;
                case 4: clk[0]++; clk[3]++; clk[6]++; break;
                case 5: clk[1]++; clk[3]++; clk[4]++; clk[5]++; clk[7]++; break;
                case 6: clk[2]++; clk[5]++; clk[8]++; break;
                case 7: clk[3]++; clk[4]++; clk[6]++; clk[7]++; break;
                case 8: clk[6]++; clk[7]++; clk[8]++; break;
                case 9: clk[4]++; clk[5]++; clk[7]++; clk[8]++; break;
        }
        for(int i=0; i<9; i++)
                clk[i] %= 4;
}

void unMove(int op)
{
        switch(op) {
                case 1: clk[0]--; clk[1]--; clk[3]--; clk[4]--; break;
                case 2: clk[0]--; clk[1]--; clk[2]--; break;
                case 3: clk[1]--; clk[2]--; clk[4]--; clk[5]--; break;
                case 4: clk[0]--; clk[3]--; clk[6]--; break;
                case 5: clk[1]--; clk[3]--; clk[4]--; clk[5]--; clk[7]--; break;
                case 6: clk[2]--; clk[5]--; clk[8]--; break;
                case 7: clk[3]--; clk[4]--; clk[6]--; clk[7]--; break;
                case 8: clk[6]--; clk[7]--; clk[8]--; break;
                case 9: clk[4]--; clk[5]--; clk[7]--; clk[8]--; break;
        }
        for(int i=0; i<9; i++)
                clk[i] = (clk[i]+4) % 4;
}

int judge()
{
        for(int i=0; i<9; i++)
                if(clk[i]>0) return 0;
        return 1;
}

int path[100];

int ddfs(int deep, int num)
{
        if(judge()) {
                sort(path, path+num);
                printf("%d", path[0]);
                for(int i=1; i<num; i++)
                        printf(" %d", path[i]);
                printf("\n");
                return 1;
        }
        if(deep==0) return 0;
        for(int i=1; i<=9; i++) {
                Move(i);
                path[num] = i;
                if(ddfs(deep-1, num+1)) return 1;
                unMove(i);
        }
        return 0;
}

int main()
{
        for(int i=0; i<9; i++)
                scanf("%d", &clk[i]);
        for(int i=1; i; i++) {
                if(ddfs(i, 0)) break;
        }

        return 0;
}
