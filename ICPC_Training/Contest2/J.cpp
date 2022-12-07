#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 7;
const int oo = 1e4;
typedef long long ll;
struct node {
    ll val;
    ll min1, min2, min3;
    ll max1, max2, max3;
} st[maxN * 4];
int n, q;
int a[maxN];

node merge(node x, node y, int value) {
    x.val = value;

    x.max1 = max(x.max1, y.max1);
    x.max2 = max(x.max2, y.max2);
    x.max3 = max(x.max3, y.max3);

    x.min1 = min(x.min1, y.min1);
    x.min2 = min(x.min2, y.min2);
    x.min3 = min(x.min3, y.min3);

    return x;
}

void push_max(int id, int v, bool l) {
    if (v >= st[id].max1)
        return;
    st[id].max1 = v;
    if (l) {
        st[id].min1 = st[id].max1;
    } else {
        if (v <= st[id].min1) {
            st[id].min1 = v;
        } else if (v < st[id].min2) {
            st[id].min2 = v;
        }
        else if (v < st[id].min3) {
            st[id].min3 = v;
        }
    }
}

void push_min(int id, int v, bool l) {
    if (v <= st[id].min1)
        return;
    st[id].min1 = v;
    if (l) {
        st[id].max1 = st[id].min1;
    } else {
        if (v >= st[id].max1) {
            st[id].max1 = v;
        } else if (v > st[id].max2) {
            st[id].max2 = v;
        }
        else if (v > st[id].max3) {
            st[id].max3 = v;
        }
    }
}

void push_down(int id, int l, int r) {
    if (l == r) return;
    int m = (l + r) >> 1;
    push_max(id * 2, st[id].max1, l == m);
    push_max(id * 2 + 1, st[id].max1, r == m + 1);

    push_min(id * 2, st[id].min1, l == m);
    push_min(id * 2 + 1, st[id].min1, r == m + 1);
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].val = a[l];
        st[id].max1 = st[id].max2 = st[id].max3 = -oo;
        st[id].min1 = st[id].min2 = st[id].min3 = +oo;
        return;
    }
    int m = (l + r) >> 1;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1], st[id].val);
}

void update(int id, int l, int r, int i, int val) {
    if (l > i || r < i) return;
    if (l == r) {
        st[id].val = (ll)val;
        return;
    }
    push_down(id, l, r);
    int m = (l + r) >> 1;
    update(2 * id, l, m, i, val);
    update(2 * id + 1, m + 1, r, i, val);
    st[id] = merge(st[id * 2], st[id * 2 + 1], st[id].val);
}

node getMin(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
        node res;
        res.val = st[id].val;
        res.max3 = res.max2 = res.max1 = -oo;
        res.min1 = res.min2 = res.min3 = oo;
        return res;
    }
    if (l >= u && r <= v) {
        return st[id];
    }
    push_down(id, l, r);
    int m = (l + r) >> 1;
    node get1 = getMin(2 * id, l, m, u, v);
    node get2 = getMin(2 * id + 1, m + 1, r, u , v);
    return merge(get1, get2, st[id].val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y);
        else {
            node aa = getMin(1, 1, n, x, y);
            cout << max(1ll * aa.max1 * aa.max2 * aa.max3, 1ll * aa.max1 * aa.min1 * aa.min2) << endl;
        }
    }
    return 0;
}