#include <stdio.h>
#include <math.h>

double num[4], t1, t2, t3;

double cal(double a, double b, double op)
{
        if(op==0) return a+b;
        if(op==1) return a-b;
        if(op==2) return a*b;
        if(op==3) return a/b;
}

int is_ok(double n)
{
        return fabs(n-24) < 0.0001;
}

void print(int op)
{
        if(op==0) putchar('+');
        if(op==1) putchar('-');
        if(op==2) putchar('*');
        if(op==3) putchar('/');
}

void print1(int i, int j, int k)
{
        printf("%.0f", num[0]);
        print(i);
        printf("%.0f", num[1]);
        print(j);
        printf("%.0f", num[2]);
        print(k);
        printf("%.0f", num[3]);
}

void print2(int i, int j, int k)
{
        printf("%.0f", num[0]);
        print(i);
        printf("(%.0f", num[1]);
        print(j);
        printf("%.0f", num[2]);
        print(k);
        printf("%.0f)", num[3]);
}

void print3(int i, int j, int k)
{
        printf("%.0f", num[0]);
        print(i);
        printf("%.0f", num[1]);
        print(j);
        printf("(%.0f", num[2]);
        print(k);
        printf("%.0f)", num[3]);
}

void print4(int i, int j, int k)
{
        printf("%.0f", num[0]);
        print(i);
        printf("(%.0f", num[1]);
        print(j);
        printf("%.0f)", num[2]);
        print(k);
        printf("%.0f", num[3]);
}

void print5(int i, int j, int k)
{
        printf("%.0f", num[0]);
        print(i);
        printf("(%.0f", num[1]);
        print(j);
        printf("(%.0f", num[2]);
        print(k);
        printf("%.0f))", num[3]);
}

int main()
{
        scanf("%lf%lf%lf%lf", &num[0], &num[1], &num[2], &num[3]);
        for(int i=0; i<4; i++) {
                t1 = cal(num[0], num[1], i);
                for(int j=0; j<4; j++) {
                        t2 = cal(t1, num[2], j);
                        for(int k=0; k<4; k++) {
                                t3 = cal(t2, num[3], k);
                                if(is_ok(t3)) { print1(i, j, k); return 0; }
                        }
                }
        }
        for(int i=0; i<4; i++) {
                t1 = cal(num[1], num[2], i);
                for(int j=0; j<4; j++) {
                        t2 = cal(t1, num[3], j);
                        for(int k=0; k<4; k++) {
                                t3 = cal(num[0], t2, k);
                                if(is_ok(t3)) { print2(k, i, j); return 0; }
                        }
                }
        }
        for(int i=0; i<4; i++) {
                t1 = cal(num[2], num[3], i);
                for(int j=0; j<4; j++) {
                        t2 = cal(num[0], num[1], j);
                        for(int k=0; k<4; k++) {
                                t3 = cal(t2, t1, k);
                                if(is_ok(t3)) { print3(j, k, i); return 0; }
                        }
                }
        }
        for(int i=0; i<4; i++) {
                t1 = cal(num[1], num[2], i);
                for(int j=0; j<4; j++) {
                        t2 = cal(num[0], t1, j);
                        for(int k=0; k<4; k++) {
                                t3 = cal(t2, num[3], k);
                                if(is_ok(t3)) { print4(j, i, k); return 0; }
                        }
                }
        }
        for(int i=0; i<4; i++) {
                t1 = cal(num[2], num[3], i);
                for(int j=0; j<4; j++) {
                        t2 = cal(num[1], t1, j);
                        for(int k=0; k<4; k++) {
                                t3 = cal(num[0], t2, k);
                                if(is_ok(t3)) { print5(k, j, i); return 0; }
                        }
                }
        }

        return 0;
}
