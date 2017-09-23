#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 1000000007;
vector<ll> bit, base;
pll dp[20][10][2][400];

pll dfs(int len, int high, int limit, int zero, int sum)
{
    pll p = pll(0, 0), q;
    if(len == 1) return high == sum ? pll(1, sum) : p;

    if(!limit && dp[len][high][zero][sum + 200].first != -1)
        return dp[len][high][zero][sum + 200];

    int end = limit ? bit[len - 1] : 9;
    for(int i = 0; i <= end; i++) {
        if(zero) q = dfs(len - 1, i, limit && i == end, i == 0, sum);
        else q = dfs(len - 1, i, limit && i == end, false, high - sum);
        p.first += q.first;
        p.second = ((p.second + q.second) % mod +
                (q.first * high % mod) * base[len] % mod) % mod;
    }
    if(!limit) dp[len][high][zero][sum + 200] = p;
    return p;
}

ll solve(ll n, ll sum)
{
    bit.clear();
    bit.push_back(0);
    while(n) {
        bit.push_back(n % 10);
        n /= 10;
    }
    return dfs(bit.size(), 0, true, true, sum).second;
}

int main()
{
    ll L, R, S;
    fill(dp[0][0][0], dp[0][0][0] + 400 * 400, pll(-1, 0));
    base.push_back(0); base.push_back(1);
    for(int i = 0; i < 20; i++) base.push_back(base[base.size() - 1] * 10 % mod);
    cin >> L >> R >> S;
    cout << (solve(R, S) - solve(L - 1, S) + mod) % mod << endl;

    return 0;
}
