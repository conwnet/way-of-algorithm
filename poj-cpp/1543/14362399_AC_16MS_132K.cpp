#include <stdio.h>

int main()
{
        int N, i, j, k, l;

        scanf("%d", &N);
        for(i=3; i<=N; i++)
        for(j=2; j<=i; j++)
        for(k=j; k<=i; k++)
        for(l=k; l<=i; l++)
        if(i*i*i==j*j*j+k*k*k+l*l*l)
        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);

        return 0;
}
