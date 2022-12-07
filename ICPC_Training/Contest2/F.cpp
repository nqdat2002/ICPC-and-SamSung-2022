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

int main() {
    int n; cin >> n;
    vector<ll> M(n), N;
    for (auto &x : M) cin >> x;
    set<ll> S;
    for (auto c : M) {
        N.pb(c * c);
        S.insert(c * c);
    }

    int vuong = 0, tu = 0, nhon = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (S.count(N[i] + N[j]))
                vuong++;
            tu += -(upper_bound(N.begin(), N.end() + j + 1, N[i] + N[j]) - N.begin()) + (lower_bound(M.begin(), M.end() + j + 1, M[i] + M[j]) - M.begin());
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = j + 1;
            while (k < n && M[i] + M[j] > M[k]) 
                k ++;
            nhon = nhon + k - j - 1;
        }
    }
    cout << nhon - vuong - tu << ' ' << vuong << " " << tu << endl;

    return 0;
}