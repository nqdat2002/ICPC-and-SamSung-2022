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

void FileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

ll gcdArr(vector<ll> a) {
    ll temp = abs(a[0]);
    for (int i = 1; i < a.size(); i++)   temp = __gcd(temp, abs(a[i]));
    return temp * 1ll;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;  cin >> t;
    while (t--) {
        ll n, k;   cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        int run = 1;
        bool cond = true;
        while (run <= n) {
            vector<bool> v(n);
            bool stop  = true;
            fill(v.end() - run, v.end(), true);
            do {
                vector<ll> temp;
                stack<ll> index;
                bool flag = true;
                for (int i = 0 ; i < n; i++) {
                    if (v[i]) {
                        if (index.size() > 0) {
                            if (abs(i - index.top()) != 1) {
                                flag = false;
                                break;
                            }
                        }
                        index.push(i);
                        temp.push_back(a[i]);
                    }
                }

                if (flag) {
                    if (gcdArr(temp) == k) {
                        cout << temp.size() << endl;
                        cond = false;
                        stop = false;
                        break;
                    }
                }
            } while (next_permutation(v.begin(), v.end()));
            if (!stop) break;
            run++;
        }
        if (cond) cout << -1 << endl;
    }
    return 0;
}