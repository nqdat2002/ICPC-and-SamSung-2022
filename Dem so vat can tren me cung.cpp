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
char a[1005][1005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n, cnt = 0;
    cin >> m >> n;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
            cin >> a[i][j];
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(a[i][j] == '#') cnt ++;
            if(a[i][j] == '#' && a[i][j + 1] == '#') cnt --;
            if(a[i][j] == '#' && a[i + 1][j] == '#') cnt --;
        }
    }
    cout << cnt << endl;
    return 0;
}
