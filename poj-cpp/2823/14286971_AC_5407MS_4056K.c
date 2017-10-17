#include <stdio.h>

int arr[1000001], N, K, sarr[1000001];

int main()
{
        int i, j, *s, *p;

        scanf("%d%d", &N, &K);
        for(i=0; i<N; i++) scanf("%d", &arr[i]);
        s = sarr, p = sarr;
        for(i=0; i<N; i++) {
                if(i>=K) { printf("%d", *s); break; }
                while(p>s && *(p-1)>arr[i]) p--;
                *p++ = arr[i];
        }
        for(; i<N; i++) {
                while(p>s && *(p-1)>arr[i]) p--;
                *p++ = arr[i];
                if(*s==arr[i-K]) s++;
                printf(" %d", *s);
        }
        printf("\n");
        s = sarr, p = sarr;
        for(i=0; i<N; i++) {
                if(i>=K) { printf("%d", *s); break; }
                while(p>s && *(p-1)<arr[i]) p--;
                *p++ = arr[i];
        }
        for(; i<N; i++) {
                while(p>s && *(p-1)<arr[i]) p--;
                *p++ = arr[i];
                if(*s==arr[i-K]) s++;
                printf(" %d", *s);
        }

        return 0;
}
