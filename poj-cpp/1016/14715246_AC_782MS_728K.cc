#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <set>

using namespace std;

string change(string s)
{
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        int l = s.size()-1;
        while(l>=0) {
                cnt[s[l]-'0']++;
                l--;
        }
        string ret;
        char str[10];
        for(int i=0; i<10; i++) {
                if(cnt[i]) {
                        sprintf(str, "%d%d", cnt[i], i);
                        ret += str;
                }
        }
        return ret;
}

int main()
{
        string S, s;
        set<string> st;

        while(cin >> S) {
                if(S[0]=='-') break;
                s = S;
                st.clear();
                st.insert(s);
                int i;
                for(i=0; i<15; i++) {
                        s = change(s);
                        if(st.find(s) != st.end()) break;
                        st.insert(s);
                }
                if(i==0) printf("%s is self-inventorying\n", S.c_str());
                else if(i==15) printf("%s can not be classified after 15 iterations\n", S.c_str());
                else if(change(s)==s) printf("%s is self-inventorying after %d steps\n", S.c_str(), i);
                else {
                        int j;
                        string ts = s;
                        for(j=1; j; j++) {
                                ts = change(ts);
                                if(ts==s) break;
                        }
                        printf("%s enters an inventory loop of length %d\n", S.c_str(), j);
                }
        }

        return 0;
}
