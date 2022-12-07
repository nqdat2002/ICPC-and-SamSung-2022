#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1000033;

ll power2(ll n, ll k) {
    if (k == 1)
        return n % mod;
    ll tmp = power2(n, k / 2);
    if (k & 1)
        return (tmp * tmp % mod) * n % mod;
    return tmp * tmp % mod;
}

ll a[1000005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    a[1] = 1;
    for (int i = 2; i < 1000000; ++i) {
        a[i] = (a[i - 1] * i % mod) % mod;
    }

    int t; cin >> t;
    while (t --) {
        ll l, r, k;
        cin >> l >> r >> k;
        if (r >= mod) {
            cout << 0 << endl;
            continue;
        }
        ll ans = 1;
        for (ll i = l; i <= r; ++i) {
            ans = ans * a[i];
            ans %= mod;
        }
        cout << power2(ans, k) << endl;
    }
    return 0;
}