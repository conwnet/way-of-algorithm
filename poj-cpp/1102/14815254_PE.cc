#include <stdio.h>
#include <string.h>

char str[32][128], num[16];
int s;

void build(int c, int n)
{
        if(n==0) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][c] = str[i+1][s+1+c] = '|';
                        str[s+2+i][c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==1) {
                for(int i=0; i<s; i++) {
                        str[i+1][s+1+c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==2) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][s+1+c] = str[s+2+i][c] = '|';
                }
        } else if(n==3) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][s+1+c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==4) {
                for(int i=0; i<s; i++) {
                        str[s+1][i+1+c] = '-';
                        str[i+1][c] = str[i+1][s+1+c] = '|';
                        str[s+2+i][s+1+c] = '|';
                }
        } else if(n==5) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==6) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][c] = str[s+2+i][c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==7) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = '-';
                        str[i+1][s+1+c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==8) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][c] = str[i+1][s+1+c] = '|';
                        str[s+2+i][c] = str[s+2+i][s+1+c] = '|';
                }
        } else if(n==9) {
                for(int i=0; i<s; i++) {
                        str[0][i+1+c] = str[s+1][i+1+c] = str[2*s+2][i+1+c] = '-';
                        str[i+1][c] = str[i+1][s+1+c] = '|';
                        str[s+2+i][s+1+c] = '|';
                }
        }
}

void print()
{
        int n = strlen(num);
        for(int i=0; i<(s*2+3); i++) {
                for(int j=0; j<n*(s+3)-1; j++)
                        printf("%c", str[i][j]);
                printf("\n");
        }
}

int main()
{
        while(scanf("%d%s", &s, num)) {
                if(s==0) break;
                memset(str, ' ', sizeof(str));
                for(int i=0; num[i]; i++) {
                        build(i*(s+3), num[i]-'0');
                }
                print();
        }

        return 0;
}
