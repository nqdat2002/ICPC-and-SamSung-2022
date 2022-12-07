#include<iostream>
#include<vector>
#include<queue>
#include <memory.h>

using namespace std;

int parents[100005]={0};
int h[100005]={0};
vector<vector<int> > g;

void BFS(int u){
    queue<int> q;
    q.push(u);
    h[u] = 0;
    parents[u]=-1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for (int i=0;i<g[front].size();i++){
            int v = g[front][i];
            if (parents[v]==0){
                q.push(v);
                parents[v]=front;
                h[v]=h[front]+1;
            }
        }
    }
}

int LCA(int u, int v){
    int count=0;
    if (h[u]<h[v]) swap(u,v);

    while(h[u]>h[v]){
        u=parents[u];
        count++;
    }
    while(u!=v){
        u=parents[u];
        v=parents[v];
        count+=2;
    }
    return count;
}

void solve(){
    memset(parents, 0, sizeof(parents));
    memset(h, 0, sizeof(h));
    int n;
    cin>>n;
    g.clear();
    g.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    BFS(1);

    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        cout<<LCA(u,v)<<endl;
    }
}

int main(){
    // freopen("input.in", "r", stdin);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}