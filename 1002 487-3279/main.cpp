//这份代码用C++提交会过，用G++不一定过，G++时间压线
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main()
{
    int dic[128];
    dic['A'] = dic['B'] = dic['C'] = '2';
    dic['D'] = dic['E'] = dic['F'] = '3';
    dic['G'] = dic['H'] = dic['I'] = '4';
    dic['J'] = dic['K'] = dic['L'] = '5';
    dic['M'] = dic['N'] = dic['O'] = '6';
    dic['P'] = dic['R'] = dic['S'] = '7';
    dic['T'] = dic['U'] = dic['V'] = '8';
    dic['W'] = dic['X'] = dic['Y'] = '9';

    int N;
    map<string, int> m;
    char line[128], num[10];

    scanf("%d", &N);
    while(N--) {
        scanf("%s", line);
        int len = 0;
        for(int i = 0; line[i]; i++) {
            if(line[i] == '-') continue;
            if(line[i] < '0' || line[i] > '9')
                line[i] = dic[line[i]];
            num[len++] = line[i];
            if(len == 3) num[len++] = '-';
        }
        num[len] = '\0';
        m[num]++;
    }
    
    int repeat = 0;
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        if(it->second > 1) {
            printf("%s %d\n", it->first.c_str(), it->second);
            repeat = 1;
        }
    }
    if(!repeat)
        printf("No duplicates.\n");

    return 0;
}
