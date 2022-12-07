#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int oo = 1e6 + 7;

#define f first
#define s second
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define ms(s, n) memset(s, n, sizeof(s))
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a.begin(), a.end())
#define For(i, l, r) for (int i = l; i <= r; i++)
#define Fod(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void FileIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const ll m = 1e6 + 5;
ll n, x, a[m], d[m], f[m];
ll ans = 0;

void update(ll x, ll val){
    while(x <= m){
        d[x] = min(d[x], val);
        x += (x & -x);
    }
}

ll get(ll x){
    ll res = n + 1;
    while(x){
        res = min(res, d[x]);
        x -= (x & -x);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> x;
    n++;
    for(ll i = 2; i <= n; i ++){
        cin >> a[i];
        a[i] -= x;
    }
    a[1] = 0;
    for(ll i = 2; i <= n; i ++){
        f[i] = f[i - 1] + a[i];
        a[i] = f[i];
    }
    for(ll i = 1; i <= n; i ++)
        d[i] = n + 2;
    sort(f + 1, f + 1 + n);
    for(ll i = 1; i <= n; i ++)
        a[i] = lower_bound(f + 1, f + 1 + n, a[i]) - f;
    update(a[1], 1);
    for(ll i = 2; i <= n; i ++){
        ll idx = get(a[i]);
        ans = max(ans, i - idx);
        update(a[i], i);
    }
    cout << ans << endl;
    return 0;
}