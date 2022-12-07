#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void Solve(ll p, ll q) {
    if(q % p == 0)  {
        cout << "1/" << q / p;
        return;
    }
    ll x = (q / p) + 1;
    cout << "1/" << x << " + ";
    Solve(p * x - q, q * x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        ll p, q; cin >> p >> q;
        Solve(p, q);
        cout << endl;
    }
    return 0;
}