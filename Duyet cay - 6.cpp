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

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} *tree;

tree MakeRoot(int value){
    tree p = new node();
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;

}
tree Search(tree t, int x){
    if(t == NULL) return NULL;
    if(t->data == x) return t;
    tree p = Search(t->left, x);
    if(p == NULL) p = Search(t->right, x);
    return p;
}
void addLeft(tree &t, int u, int v){
    tree p = Search(t, u), q;
    if(p == NULL) return;
    if(p->left == NULL) {
        q = MakeRoot(v);
        p->left = q;
    }
}

void addRight(tree &t, int u, int v){
    tree p = Search(t, u), q;
    if(p == NULL) return;
    if(p->right == NULL) {
        q = MakeRoot(v);
        p->right = q;
    }
}

void Reverse_Spiral_Order(tree root){
    if(root == NULL) return;
    stack <tree> st;
    queue <tree> q;
    q.push(root);
    while(q.size()){
        tree tmp = q.front(); q.pop();
        st.push(tmp);
        if(tmp->right){
            q.push(tmp->right);
        }
        if(tmp->left){
            q.push(tmp->left);
        }
    }
    while(st.size()){
        tree tmp = st.top(); st.pop();
        cout << tmp->data << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        tree root = NULL;
        for(int i = 0; i < n; ++i){
            int u, v; char x; 
            cin >> u >> v >> x;
            if(root == NULL){
                root = MakeRoot(u);
            }
            if(x == 'L') addLeft(root, u, v);
            else addRight(root, u, v);
        }
        Reverse_Spiral_Order(root);
        cout << endl;
    }
    return 0;
}