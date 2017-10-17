#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct BigInteger {
        static const int BASE = 10000;
        static const int WIDTH = 4;
        vector<int> s;

        ///重载赋值运算符
        BigInteger(long long num = 0) { *this = num; }
        BigInteger operator = (long long num)
        {
                s.clear();
                do {
                        s.push_back(num%BASE);
                        num /= BASE;
                } while(num>0);
                return *this;
        }
        BigInteger operator = (const string& str)
        {
                s.clear();
                int x, len = (str.length()-1) / WIDTH + 1;

                for(int i=0; i<len; i++) {
                        int end = str.length() - i*WIDTH;
                        int start = max(0, end-WIDTH);
                        sscanf(str.substr(start, end-start).c_str(), "%d", &x);
                        s.push_back(x);
                }
                return *this;
        }

        ///重载比较运算符
        bool operator < (const BigInteger& b) const {
                if(s.size()!=b.s.size()) return s.size() < b.s.size();
                for(int i=s.size()-1; i>=0; i--)
                        if(s[i] != b.s[i]) return s[i]<b.s[i];
                return false;
        }
        bool operator > (const BigInteger& b) const { return b<*this; }
        bool operator <= (const BigInteger& b) const { return !(b<*this); }
        bool operator >= (const BigInteger& b) const { return !(*this<b); }
        bool operator != (const BigInteger& b) const { return b<*this || *this<b; }
        bool operator == (const BigInteger& b) const { return !(b<*this) && !(*this<b);}

        ///四则运算
        BigInteger operator + (const BigInteger& b) const {
                BigInteger c;
                c.s.clear();
                for(int i=0, g=0; ; i++) {
                        if(g==0 && i>=s.size() && i>=b.s.size()) break;
                        int x = g;
                        if(i<s.size()) x += s[i];
                        if(i<b.s.size()) x += b.s[i];
                        c.s.push_back(x%BASE);
                        g = x/BASE;
                }
                return c;
        }
        BigInteger operator - (const BigInteger& b) const {
                BigInteger c;
                c.s.clear();
                for(int i=0, g=0; ; i++) {
                        if(g==0 && i>=s.size() && i>=b.s.size()) break;
                        int x = g;
                        if(i<s.size()) x += s[i];
                        if(i<b.s.size()) x -= b.s[i];
                        c.s.push_back(x>=0?x:x+BASE);
                        g = x>=0?0:-1;
                }
                return c;
        }

        BigInteger operator * (const BigInteger& b) const {
                int g, x, i, j;
                BigInteger c;
                c.s.clear();
                for(i=0; i<s.size(); i++) {
                        g = 0;
                        for(j=0; j<b.s.size(); j++) {
                                x = g+s[i]*b.s[j];
                                if(i+j<c.s.size()) c.s[i+j] = (x+=c.s[i+j])%BASE;
                                else c.s.push_back(x%BASE);
                                g = x/BASE;
                        }
                        if(g!=0) {
                                if(i+j<c.s.size()) c.s[i+j] = (g+=c.s[i+j])%BASE;
                                else c.s.push_back(g%BASE);
                                g = g/BASE;
                        }
                }
                return c;
        }

        ///除法慎用，结果很大时很慢
        BigInteger operator / (const BigInteger& b) const {
                BigInteger c;
                c.s.clear();
                for(c=0; ; c=c+1) {    ///how to binary searcher?
                        if(*this<c*b) break;
                }
                return c-1;
        }


};

///重载流操作运算符
ostream& operator << (ostream& out, const BigInteger& x)
{
        out << x.s.back();
        if(x.s.back()==0) return out;
        for(int i=x.s.size()-2; i>=0; i--) {
                char buf[20];
                sprintf(buf, "%04d", x.s[i]);
                for(int j=0; j<strlen(buf); j++) out << buf[j];
        }
        return out;
}
istream& operator >> (istream& in, BigInteger& x)
{
        string s;
        if(!(in>>s)) return in;
        while(s[0]=='0' && s.size()>1) s.erase(s.begin());   ///去前导0...
        x = s;
        return in;
}

BigInteger d[110];

int main()
{
        d[0] = 1;
        for(int i=1; i<=100; i++) {
                int k = i-1;
                for(int j=0; j<=k; j++)
                        d[i] = d[i] + d[j]*d[k-j];
        }
        int n;
        while(scanf("%d", &n) && -1!=n) {
                cout << d[n] << endl;
        }

        return 0;
}

