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

int MOD = 1e9 + 7;
const int INF = (int)1e9 + 7;
const ll INFLL = (ll)1e18 + 7;
const int maxn = 1000001;

int n;
ll cash[maxn];
vector<ll> pref;
ll sum(int op, int gg) { return pref[op] - pref[gg - 1]; }
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin >> n >> T;

    for (int i = 1; i <= n; i++) cin >> cash[i];

    sort(cash + 1, cash + n + 1);
    pref.emplace_back(cash[1]);
    for (int i = 1; i < n; i++) pref.push_back(pref[i - 1] + cash[i + 1]);

    while (T--) {
        ll val; cin >> val;
        vector<ll>::iterator pos;
        pos = lower_bound(pref.begin(), pref.end(), val);
        if (pref[pos - pref.begin()] - val) {
            int left = 1;
            pos--;
            while (cash[pos - pref.begin() + left + 1] + sum(pos - pref.begin() + left - 1, left) <= val) {
                left++;
            }
            int leng = pos - pref.begin() + 1;
            ll minval = cash[left];
            cout << leng << " " << minval << endl;
        } else
            cout << pos - pref.begin() + 1 << " " << cash[1] << endl;
    }
    return 0;
}