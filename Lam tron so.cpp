#include <iostream>
#include<string>
using namespace std;
int main(){
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s;
		while (n>=10) {
			int x = n % 10;
			n /= 10;
			if (x < 5)s = "0" + s;
			else {
				s = "0" + s;
				n++;
			}	
		}
		s = to_string(n) + s;
		cout << s << endl;
	}
}