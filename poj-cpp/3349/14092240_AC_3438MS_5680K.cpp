#include <stdio.h>
#include <string.h>

struct ADT{
       int a[6];
       ADT *next;
       ADT(int arr[])
       {
               for(int i=0; i<6; i++) a[i] = arr[i];
               next = 0;
       }
       bool operator == (const ADT& b) const{
                int i, j, k, t, faild=0;
                for(i=0; i<6; i++) {
                        for(j=0; j<6; j++) {
                                t = i+j;
                                if(t>5) t -= 6;
                                if(a[j]!=b.a[t]) {
                                        faild ++;
                                        break;
                                }
                        }
                }
                for(i=0; i<6; i++) {
                        for(j=0; j<6; j++) {
                                t = i+(5-j);
                                if(t>5) t -= 6;
                                if(a[j]!=b.a[t]) {
                                        faild ++;
                                        break;
                                }
                        }
                }
                if(faild==12) return 0;
                return 1;
       }
}*head[101000]={0};

int N;

int main()
{
        int i, arr[6], ok=0;

        scanf("%d", &N);
        while(N--) {
                int sum = 0;
                for(i=0; i<6; i++) scanf("%d", &arr[i]);
                if(!ok){
                        ADT *s = new ADT(arr);
                        for(i=0; i<6; i++) sum += arr[i];
                        sum %= 10999;
                        s->next = head[sum];
                        head[sum] = s;
                        ADT *t = s->next;
                        while(1) {
                                if(t==0) break;
                                if(*t==*s) {
                                        ok = 1;
                                        break;
                                }
                                t = t->next;
                        }
                }
        }
        if(ok) printf("Twin snowflakes found.\n");
        else printf("No two snowflakes are alike.\n");

        return 0;
}
