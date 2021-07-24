#include <stdio.h>

typedef long long ll;
ll vals[100010 * 4], lazy[100010 * 4];

void push_down(int o, int l, int r)
{
    if (l == r || !lazy[o]) {
        return;
    }
    int m = (l + r) >> 1;
    vals[o * 2] += lazy[o] * (m - l + 1);
    vals[o * 2 + 1] += lazy[o] * (r - m);
    // just *add* current lazy to each of its children's
    lazy[o * 2] += lazy[o];
    lazy[o * 2 + 1] += lazy[o];
    lazy[o] = 0;
}

void change(int o, int l, int r, int L, int R, int val)
{
    // ensure every node and its chilren has updated
    push_down(o, l, r);
    if (L <= l && R >= r) {
        vals[o] += (r - l + 1) * val;
        lazy[o] = val;
        push_down(o, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) change(o * 2, l, m, L, R, val);
    if (R > m) change(o * 2 + 1, m + 1, r, L, R, val);
    vals[o] = vals[o * 2] + vals[o * 2 + 1];
}

ll query(int o, int l, int r, int L, int R)
{
    push_down(o, l, r);
    if (L <= l && R >= r) {
        return vals[o];
    }
    ll sum = 0;
    int m = (l + r) >> 1;
    if (L <= m) sum += query(o * 2, l, m, L, R);
    if (R > m) sum += query(o * 2 + 1, m + 1, r, L, R);
    return sum;
}

int main()
{
    char op[5];
    int N, Q, L, R, V, n;

    scanf("%d%d", &N, &Q);

    for (int i = 0; i <= N * 4; i++) {
        vals[i] = lazy[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        change(1, 1, N, i, i, n);
    }

    while (Q--) {
        scanf("%s", op);
        if (op[0] == 'Q') {
            scanf("%d%d", &L, &R);
            printf("%lld\n", query(1, 1, N, L, R));
        } else if (op[0] == 'C') {
            scanf("%d%d%d", &L, &R, &V);
            change(1, 1, N, L, R, V);
        }
    }

    return 0;
}
