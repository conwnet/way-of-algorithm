#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

void change(char *str, char *tstr);

int main(){
    char *str = (char *)malloc(50), *tstr  = (char *)malloc(10);
    map<string, int> tel;
    int n, i, jd;
    while(scanf("%d", &n)!=EOF){
        jd = 0;
        tel.clear();
        for(i=0; i<n; i++){
            scanf("%s", str);
            change(str, tstr);
            tel[tstr]++;
        }
        map<string, int>::iterator ttel;
        for(ttel=tel.begin(); ttel!=tel.end(); ttel++){
            if(ttel->second != 1){
                cout << ttel->first << " " << ttel->second << "\n";
                jd = 1;
            }
        }
        if(0==jd) printf("No duplicates.\n");
    }
    return 0;
}

void change(char *str, char *tstr){
    char c;
    char *p = str;
    int i=0;
    for(c=*p; c!='\0'; c=*++p){
        if(i==3) tstr[i++] = '-';
        if(c=='-') continue;
        else if(isalpha(c)){
            switch(c){
                case 'A':
                case 'B':
                case 'C':tstr[i++] = '2'; break;
                case 'D':
                case 'E':
                case 'F':tstr[i++] = '3'; break;
                case 'G':
                case 'H':
                case 'I':tstr[i++] = '4'; break;
                case 'J':
                case 'K':
                case 'L':tstr[i++] = '5'; break;
                case 'M':
                case 'N':
                case 'O':tstr[i++] = '6'; break;
                case 'P':
                case 'R':
                case 'S':tstr[i++] = '7'; break;
                case 'T':
                case 'U':
                case 'V':tstr[i++] = '8'; break;
                case 'W':
                case 'X':
                case 'Y':tstr[i++] = '9'; break;
            }
        }
        else if(c>='0' && c<='9') tstr[i++] = c;
    }
    tstr[i] = '\0';
}
