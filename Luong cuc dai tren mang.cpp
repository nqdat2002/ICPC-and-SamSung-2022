#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> p;
typedef vector<vector<int> > vt;
typedef vector<pair<int, int> > vp;

const ll mod = 1e9 + 7;
const int nmax = 1e6 + 7;

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
const int oo = 1 << 29;

struct edge{
    int x, y, cap, flow;
};

struct Flow{
    int n, S, T;
    vector < vector <int> > a;
    vector <int> cur, d;
    vector <edge> e;

    Flow() {}
    Flow(int _n, int _S, int _T){
        n = _n; S = _S; T = _T;
        a = vector < vector <int> >(n + 1);
        cur = vector <int>(n + 1);
        d = vector <int>(n + 1);
    }

    void addEdge(int x, int y, int _cap){
        edge e1 = {x, y, _cap, 0};
        edge e2 = {y, x, 0, 0};
        a[x].push_back(e.size()); e.push_back(e1);
        a[y].push_back(e.size()); e.push_back(e2);
    }

    int bfs(){
        queue <int> q;
        for (int i = 1; i <= n; i++) d[i] = -1;
        q.push(S); d[S] = 0;
        while (!q.empty() && d[T] < 0){
            int x = q.front(); q.pop();
            for (int i = 0; i < int(a[x].size()); i++){
                int id = a[x][i], y = e[id].y;
                if (d[y] < 0 && e[id].flow < e[id].cap)
                    q.push(y), d[y] = d[x] + 1;
            }
        }
        return d[T] >= 0;
    }

    int dfs(int x, int val){
        if (!val) return 0;
        if (x == T) return val;
        for (; cur[x] < int(a[x].size()); cur[x]++){
            int id = a[x][cur[x]], y = e[id].y;
            if (d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(val, e[id].cap - e[id].flow));
            if (pushed){
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow(){
        int res = 0;
        while (bfs()){
            for (int i = 1; i <= n; i++) cur[i] = 0;
            while (1){
                int val = dfs(S, oo);
                if (!val) break;
                res += val;
            }
        }
        return res;
    }   
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, S, T, x, y, z;
    cin >> n >> m >> S >> T;
    Flow u(n, S, T);
    while (m--){
        cin >> x >> y >> z;
        u.addEdge(x, y, z);
    }
    cout << u.maxFlow() << endl;
    return 0;
}
