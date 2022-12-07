#include<bits/stdc++.h>

using namespace std;
int a[20005], b[20005], c[100005], pre[100005];
int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int index = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
        c[++index] = a[i] - 1;
        c[++index] = a[i];
        c[++index] = b[i];
        c[++index] = b[i] + 1;
    }
    sort(c + 1, c + index + 1);
    int d = unique(c + 1, c + index + 1) - c - 1;
    for (int i = 1; i <= n; ++i){
        int pos_a = lower_bound(c + 1, c + d + 1, a[i]) - c - 1;
        int pos_b = lower_bound(c + 1, c + d + 1, b[i]) - c - 1;
        pre[1] += x;
        pre[pos_a] += y - x;
        pre[pos_b + 1] += z - y;
    }
    int res = 0;
    for (int i = 2; i <= d; ++i){
        pre[i] += pre[i - 1];
        res = max(res, pre[i]);
    }
    cout << res << endl;
    return 0;
}
