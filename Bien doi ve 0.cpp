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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        n -= 2;
        if (n < 0) {
            cout << "9\n";
            continue;
        }
        int a = 10;
        int tg = 1;
        while (n > 0) {
            if (tg == 10) tg = 1;
            int c = to_string(a + 1).size() - 1;
            if (to_string(a).size() == c) {
                a++;
                n--;
            }
            int b = pow(10, c) - a % 10;
            b -= b % tg;
            if (b + a % 10 == pow(10, c) || b + a % 10 + 1 == pow(10, c)) {
                if (tg == 1) b -= 2;
                else b -= tg;

            }
            if (n <= b / tg) {
                a += n * tg;
                break;
            }
            a += b + tg + 1;
            if (to_string(a).size() == c + 2) a -= a % 10 + 1;
            n -= b / tg + 1;
            tg++;
        }
        cout << a << "\n";
    }
    return 0;
}