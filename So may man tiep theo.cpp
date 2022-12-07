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

int n, a[100];
int b[2] = {4 , 7};
vector <ll> res;
void in(){
	ll tmp = 0;
	for(int i = 1; i <= n; i ++){
		tmp = tmp * 10 + b[a[i]];
	}
	res.push_back(tmp);
}

void Try(int i){
	for(int j = 0; j <= 1; j ++){
		a[i] = j;
		if(i == n) in();
		else Try(i + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	for(n = 1; n <= 9; n ++)
		Try(1);
//	for(int m = 0; m < res.size(); m++) cout << res[m] << endl;
//	cout << res.size() << endl;
	long long x, y, sum = 0;
	cin >> x >> y;
	int m = 0;
	while(x <= y){
		if(x <= res[m] && y <= res[m]){
			sum = sum + (y - x + 1) * res[m];
			x = res[m] + 1;
		}
		if(x <= res[m] && y >= res[m]){
			sum = sum + (res[m] - x + 1) * res[m];
			x = res[m] + 1;
		}
		else
			m = m + 1;
	}
	cout << sum << endl;
	return 0;
}

