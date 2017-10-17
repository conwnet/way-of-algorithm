#include <stdio.h>
#include <string.h>

/// 计算高精度 a * b ，结果以倒序保存在 c 中
/// 需要注意的是字符数组c不是以 '\0' 结尾的，返回字符数组 c 的有效长度
int mutiply(char *a, char *b, char *c)
{
    int la = strlen(a), lb = strlen(b), len = 0, i, j, x, y;
    for(i = 0; a[i]; i++) {
        x = a[la - i - 1] - '0';
        for(j = 0; b[j]; j++) {
            y = b[lb - j - 1] - '0';
            if(c[i + j] == -1) c[i + j] = x * y;
            else c[i + j] += x * y;
        }
        /// 处理进位
        for(j = 0; c[j] != -1; j++) {
            if(c[j] > 9) {
                if(c[j + 1] == -1) c[j + 1] = c[j] / 10;
                else c[j + 1] += c[j] / 10;
                c[j] %= 10;
            }
        }
    }
    while(c[len] != -1) c[len++] += '0';
    return len;
}

int main()
{
    int n, f, p, q, len;
    char a[1024], b[1024], c[1024];

    while(~scanf("%s%d", a, &n)) {
        /// 计算小数位数
        for(p = 0, q = 0, f = 0; a[q]; q++) {
            if(p) f++;
            if(a[q] == '.') p = 1;
        }
        f = f * n;
        /// 去掉前导0和小数点
        for(q = 0; a[q] <= '0' || a[q] > '9'; q++);
        for(p = 0; a[q]; q++) {
            if(a[q] >= '0' && a[q] <= '9')
                a[p++] = a[q];
        }
        a[p] = '\0';
        /// 计算 a 的 n 次方，最终结果在 b 中
        b[0] = '1'; b[1] = '\0';
        while(n--) {
            memset(c, -1, sizeof(c));
            len = mutiply(a, b, c);
            /// 由于 c 是逆序的，所以把 c 再逆序存到 b 中
            for(p = 0; p < len; p++)
                b[p] = c[len - p - 1];
            b[p] = '\0';
        }
        /// 处理结果末尾无用的 0
        while(f > 0 && b[len - 1] == '0') {
            b[--len] = '\0'; f--;
        }
        /// 处理结果小于 1 的情况
        if(f > len) {
            putchar('.');
            for(p = 0; p + len < f; p++)
                putchar('0');
        }
        ///输出结果
        for(p = 0; p < len; p++) {
            if(len - p == f) putchar('.');
            putchar(b[p]);
        }
        putchar('\n');
    }

    return 0;
}

