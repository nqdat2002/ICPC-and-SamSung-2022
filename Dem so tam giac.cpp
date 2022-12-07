#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
int bit[maxn][maxn];
typedef long long ll;
void update(int x, int y) {
    int y1;
    while (x < maxn) {
        y1 = y;
        while (y1 < maxn) {
            bit[x][y1]++;
            y1 += y1 & (-y1);
        }
        x += x & (-x);
    }
}

ll query(int x, int y) {
    ll ans = 0;
    int y1;
    while (x > 0) {
        y1 = y;
        while (y1 > 0) {
            ans += bit[x][y1];
            y1 -= y1 & (-y1);
        }
        x -= x & (-x);
    }
    return ans;
}

ll countPoints(int x1, int y1, int x2, int y2) {
    return (ll)query(x2, y2) - (ll)query(x1 - 1, y2) - (ll)query(x2, y1 - 1) + (ll)query(x1 - 1, y1 - 1);
}

ll countTriangles(ll n) {
    return (ll)(n * (n - 1) * (n - 2)) / 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int> > v;
    int q; cin >> q;
    while (q--) {
        int type, x, y, a, b; 
        cin >> type;
        if (type == 1) {
            cin >> x >> y;
            v.push_back({x, y});
            update(x, y);
        }
        else if (type == 2){
            cin >> a >> b >> x >> y;
            ll numPoints = countPoints(a, b, x, y);
            ll res = countTriangles(numPoints);
            cout << res << endl;
        }
    }
    return 0;
}