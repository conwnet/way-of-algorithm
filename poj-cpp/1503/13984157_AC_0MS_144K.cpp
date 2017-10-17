
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[1024], i, sum[1024], l, j;
    char str[1024];

    memset(sum, 0, sizeof(sum));
    while(scanf("%s", str)){
        if(str[0]=='0' && str[1]=='\0') break;
        l = strlen(str);
        //maxl = max(maxl, l);
        for(i=l-1, j=0; i>=0; i--){
                arr[j++] = str[i]-'0';
        }
        for(i=0; i<l; i++){
                sum[i] += arr[i];
        }
    }
    for(i=0; i<1023; i++){
        if(sum[i]>=10){
                sum[i+1] += sum[i]/10;
                sum[i] %= 10;
        }
    }
    for(i=1023; sum[i]==0; i--);
    for(; i>=0; i--){
        printf("%d", sum[i]);
    }
    printf("\n");

    return 0;
}
