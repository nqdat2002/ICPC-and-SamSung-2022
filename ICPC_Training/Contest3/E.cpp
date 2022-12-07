#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int gcd_extend(int a, int b, int *x, int *y) {
	if (b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}
	int x1, y1;
	int gcd = gcd_extend(b, a % b,  &x1, &y1);
	*x = y1;
	*y = x1 - (a / b) * y1;
	return gcd;
}

int modulo_inverse_euclidean(int n, int m) {
	int x, y;
	if (gcd_extend(n, m, &x, &y) != 1) return -1;
	return (x % m  + m) % m;
}

ll modulo_combination(int n, int k, int m) {
	int a = 1, b = 1, c = 1;
	for (int i = 2; i <= n; i++) {
		a = ((ll)a * i) % m;
	}
	for (int i = 2; i <= n - k; i++) {
		b = ((ll)b * i) % m;
	}
	for (int i = 2; i <= k; i++) {
		c = ((ll)c * i) % m;
	}
	b = ((ll) b * c) % m;
	return ((ll) a * modulo_inverse_euclidean(b, m)) % m;
}

int main(){
	int n, k; cin >> k >> n;
	cout << modulo_combination(n + k - 1, k, mod) << endl;
}