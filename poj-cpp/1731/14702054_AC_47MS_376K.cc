#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[201];

int main()
{
        scanf("%s", &str);
        int l = strlen(str);
        sort(str, str+l);
        do {
                for(int i=0; i<l; i++)
                        putchar(str[i]);
                putchar('\n');
        } while(next_permutation(str, str+l));

        return 0;
}

