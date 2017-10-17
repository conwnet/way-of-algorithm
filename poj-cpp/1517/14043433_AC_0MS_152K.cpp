#include <stdio.h>

int jiecheng(int n);

int main()
{
    int n, i;
    double sum;

    printf("n e\n- -----------\n");
    printf("0 1\n");
    sum = 1;
    for(i=1; i<=9; i++) {
        sum += 1.0/jiecheng(i);
        printf("%d %.10lg\n", i, sum);
    }
    return 0;
}

int jiecheng(int n)
{
        if(n==1) return 1;
        else return n*jiecheng(n-1);
}
