#include <stdio.h>
#include <string.h>

int arr[25][25];

int main()
{
        int N, S;

        scanf("%d%d", &N, &S);
        int p = S;
        for(int i=1; i<=N; i++) {
                for(int j=1; j<=i; j++) {
                        arr[j][i] = p;
                        p++;
                        if(p==10) p = 1;
                }
        }
        for(int i=1; i<=N; i++) {
                if(!arr[i][1]) printf(" ");
                else printf("%d", arr[i][1]);
                for(int j=2; j<=N; j++)
                        if(!arr[i][j]) printf("  ");
                        else printf(" %d", arr[i][j]);
                printf("\n");
        }

        return 0;
}
