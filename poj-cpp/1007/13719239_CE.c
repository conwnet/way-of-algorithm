#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[52];

typedef struct ListElement{
    String dnastr;
    int num;
    struct ListElement *next;
}lst;

lst *dna = (lst*)malloc(sizeof(lst));
int dnasize = 0;

int exnum(String str, int n);
void lstsort(lst *p, int n);
void initlist(lst *p, int n);

int main(){
    lst *p;
    String str;
    int m, n, i;

    initlist(dna, 128);
    p = dna->next;
    while(scanf("%d%d", &n, &m)!=EOF){
        for(i=0; i<m; i++){
            scanf("%s", str);
            strcpy(p->dnastr, str);
            p->num = exnum(str, n);
            p = p->next;
            dnasize++;
        }
        lstsort(dna, dnasize);
        p = dna->next;
        for(i=0; i<dnasize; i++){
            printf("%s\n", p->dnastr);
            p = p->next;
        }
    }

    return 0;
}

void initlist(lst *p, int n){
    lst *t, *tt;
    int i;
    t = p;
    t->num = 0;
    memset(t->dnastr, 0, 52);
    for(i=0; i<n; i++){
        tt = (lst*)malloc(sizeof(lst));
        tt->num = 0;
        memset(tt->dnastr, 0, 52);
        t->next = tt;
        t = t->next;
    }
    t->next = NULL;
}

int exnum(String str, int n){
    int cnt=0, i, j;
    char tstr[52], t;
    strcpy(tstr, str);
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if(tstr[j]>tstr[j+1]){
                t = tstr[j];
                tstr[j] = tstr[j+1];
                tstr[j+1] = t;
                cnt++;
            }
        }
    }
    return cnt;
}

void lstsort(lst *p, int n){
    lst *t = p, *t1, *t2, *t3;
    int i, j, k;
    for(i=n-1; i>0; i--){
        for(j=0; j<i; j++){
            if((t->next->num)>(t->next->next->num)){
                t2 = t->next;
                t3 = t2->next;
                t->next = t3;
                t2->next = t3->next;
                t3->next = t2;
            }
            t = t->next;
        }
        t = p;
    }
}
