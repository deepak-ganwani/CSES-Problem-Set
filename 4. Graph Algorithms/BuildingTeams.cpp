#include <bits/stdc++.h>
using namespace std;
#define int long long
int f=1;
void dfs(vector<vector<int>>& gr, vector<int>& vis, int node, int col) {
    vis[node]=col;
    for(int child:gr[node]) {
        if(vis[child]) {
            if(vis[child]==col) f=0;
            continue;
        } 
        dfs(gr, vis, child, (col==1?2:1));
    }
}
inline void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> gr(n+1);
    vector<int> vis(n+1,0);
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i=1; i<=n; i++) {
        if(!vis[i]) dfs(gr, vis, i, 1);
    }
    if(!f) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(int i=1; i<=n; i++) cout<<vis[i]<<" ";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}