#include <stdio.h>

int get_n(char *str);

int main()
{
        int N, i;
        char str[50];

        scanf("%d", &N);
        while(N--) {
                scanf("%s", str);
                printf("%d", get_n(str));
                for(i=8; i<32; i+=8) {
                        printf(".%d", get_n(str+i));
                }
                printf("\n");
        }

        return 0;
}

int get_n(char *str)
{
        int i, sum;

        for(i=0, sum=0; i<8; i++) {
                sum += (1<<(7-i))*(str[i]-'0');
        }

        return sum;
}
