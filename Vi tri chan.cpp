#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;
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

int m, d;
string a, b;
const int mod = 1000 * 1000 * 1000 + 7;
const int N = 2025;

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int z[N][N][2];

int solve(string s) {
    int n = s.length();
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 2; ++k) {
                z[i][j][k] = 0;
            }
        }
    }
    z[0][0][1] = 1;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
                    if ((i & 1) && p != d) continue;
                    if (!(i & 1) && p == d) continue;
                    if (!i && !p) continue;
                    int ni = i + 1;
                    int nj = (j * 10 + p) % m;
                    int nk = k && (p == int(s[i] - '0'));
                    z[ni][nj][nk] = add(z[ni][nj][nk], z[i][j][k]);
                }
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < 2; ++k) ans = add(ans, z[n][0][k]);
    return ans;
}

bool good(string s) {
    int rm = 0, l = s.length();
    for (int i = 0; i < l; ++i) {
        int p = int(s[i] - '0');
        if ((i & 1) && p != d) return false;
        if (!(i & 1) && p == d) return false;
        rm = (rm * 10 + p) % m;
    }
    return !rm;
}

int main() {
    cin >> m >> d >> a >> b;
    int ans = 0;
    ans = add(ans, solve(b));
    ans = sub(ans, solve(a));
    ans = add(ans, good(a));
    cout << ans << endl;
    return 0;
}
