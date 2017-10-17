//这份代码使用了字典树，能正常通过
#include <stdio.h>
#include <string.h>

int dic[262144][10], val[262144], dcnt = 1;

void insert(char *s)
{
    int p = 0;
    for(int i = 0; s[i]; i++) {
        int idx = s[i] - '0';
        if(dic[p][idx] == 0)
            dic[p][idx] = dcnt++;
        p = dic[p][idx];
    }
    val[p]++;
}

int repeat;
char num[10];
void dfs(int p, int d)
{
    if(val[p] > 1) {
        for(int i = 0; i < d; i++) {
            if(i == 3) putchar('-');
            putchar(num[i]);
        }
        printf(" %d\n", val[p]);
        repeat = 1;
    }
    for(int i = 0; i < 10; i++) {
        if(dic[p][i] > 0) {
            num[d] = '0' + i;
            dfs(dic[p][i], d + 1);
        }
    }
}

int main()
{
    int hash[128];
    hash['A'] = hash['B'] = hash['C'] = '2';
    hash['D'] = hash['E'] = hash['F'] = '3';
    hash['G'] = hash['H'] = hash['I'] = '4';
    hash['J'] = hash['K'] = hash['L'] = '5';
    hash['M'] = hash['N'] = hash['O'] = '6';
    hash['P'] = hash['R'] = hash['S'] = '7';
    hash['T'] = hash['U'] = hash['V'] = '8';
    hash['W'] = hash['X'] = hash['Y'] = '9';

    int N;
    char line[128];

    memset(dic, 0, sizeof(dic));
    memset(val, 0, sizeof(val));
    scanf("%d", &N);
    while(N--) {
        scanf("%s", line);
        int p = 0, q;
        for(q = 0; line[q]; q++) {
            if(line[q] == '-') continue;
            if(line[q] < '0' || line[q] > '9')
                line[q] = hash[line[q]];
            line[p++] = line[q];
        }
        line[p] = '\0';
        insert(line);
    }
    repeat = 0;
    dfs(0, 0);
    if(!repeat)
        printf("No duplicates.\n");

    return 0;
}
