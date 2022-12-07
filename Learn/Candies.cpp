#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, a, b, c, x, y;
	cin >> n >> a >> b;
	c = (b << 1) / n * n;
	if(c <= (a << 1))
		x = a, y = a;
	else{
		if(c >= a + b)
			x = b, y = c - b;
		else
			x = c - a, y = a;
	}
	cout << x << " " << y << endl;
	return 0;
}