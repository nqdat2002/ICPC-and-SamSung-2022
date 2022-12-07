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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int n = s.length(), cnt = 0;
		stack<char> st;
		for(int i = 0; i < n; ++i){
			if(s[i] == ')' && !st.empty()){
				if(st.top() == '(') st.pop();
				else st.push(s[i]);
			}
			else st.push(s[i]);
		}
		n = st.size();
		while(!st.empty() && st.top() == '('){
			++cnt;
			st.pop();
		}
		cout << n / 2 + cnt % 2 << endl;
	}
	return 0;
 }