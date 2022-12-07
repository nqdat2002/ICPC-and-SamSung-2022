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

// Author: Nguyen Quoc Dat
// ID: B20DCPT053
// Organization: PTIT
// Date: 02/03/22 21:19
// Program: Bieu thuc tang giam
// -------------------  Your code STARTS here !!!---------------------------

int main() {
	int t; cin >> t;
	for(int j = 1; j <= t; ++j){
		string s; cin >> s;
		stack<int> stk;
		int n = s.size();
		string res = "";
		for(int i = 0; i <= n; ++i){
			stk.push(i + 1);
			if(s[i] == 'I' || i == n){
				while(!stk.empty()){
					res += to_string(stk.top());
					stk.pop();
				}
			}
		}
		cout <<"Test " << j << ": " << res << endl;
	}
	return 0;
}
