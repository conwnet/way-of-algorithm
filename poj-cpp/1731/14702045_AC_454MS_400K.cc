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
                printf("%s\n", str);
        } while(next_permutation(str, str+l));

        return 0;
}
