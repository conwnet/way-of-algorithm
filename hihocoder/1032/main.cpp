#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

// f[i] 表示以 i 为中心的回文串的最大长度
// f[i] >= min(f[j - i + j], f[j] - 2 * (i - j))
// j 是边界最右的回文串的中心位置

const int maxn = 2000010;
char str[maxn];
int f[maxn];

int main()
{
    int N;
    scanf("%d", &N);
    while(N--) {
        scanf("%s", str);
        int len = strlen(str);

        // 就在所有字符之间插入 '.'，构造成奇数长度
        for(int i = len - 1, j = len * 2 - 1; i >= 0; i--) {
            str[j--] = str[i];
            str[j--] = '.';
        }
        len = len * 2 + 1;
        str[0] = '^';
        str[len - 1] = '$';
        memset(f, 0, sizeof(f));
        int j = 0, r = 0, res = 1;
        for(int i = 0; i < len; i++) {
            if(i < r) f[i] = min(f[j + j - i], f[j] - 2 * (i - j)); // AC
            // if(i < r) f[i] = f[j + j - i]; // TLE
            // Why, min(a, b) <= a !== true ?
            if(f[i] < 1) f[i] = 1;

            int m = f[i] / 2 + 1;
            while(str[i - m] == str[i + m])
                m++, f[i] += 2;

            if(f[i] / 2 + i > r) r = f[i] / 2 + i, j = i;

            if(str[i + m - 1] == '.') res = max(res, f[i] / 2);
            else res = max(res, f[i] / 2 + 1);
        }

        printf("%d\n", res);
    }

    return 0;
}

