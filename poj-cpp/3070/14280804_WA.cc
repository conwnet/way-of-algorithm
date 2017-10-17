#include <stdio.h>

struct MATR {
        int a, b, c, d;
        MATR operator * (const MATR& B) const {
                return MATR { a*B.a+b*B.c, a*B.b+b*B.d, c*B.a+d*B.c, c*B.b+d*B.d };
        }
        void mod() {
                a %= 10000;
                b %= 10000;
                c %= 10000;
                d %= 10000;
        }
};

MATR power(MATR m, int n);

int main()
{
        int n;
        MATR m = {1, 1, 1, 0};

        while(scanf("%d", &n)) {
                if(n==-1) break;
                printf("%d\n", power(m, n).b);
        }

        return 0;
}

MATR power(MATR m, int n)
{
        if(n==0) return m;
        if(n==1) return m;
        MATR t = power(m, n/2);
        t = t*t;
        t.mod();
        if(n&1) t = t*m;
        t.mod();
        return t;
}



