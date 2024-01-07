#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(vector<vector<int>>& gr, vector<int>& vis, int node) {
    vis[node]=1;
    for(int child:gr[node]) {
        if(vis[child]) continue;
        dfs(gr, vis, child);
    }
}
inline void solve(){
    int n, k; cin>>n>>k;
    vector<vector<int>> gr(n+1);
    vector<int> vis(n+1,0), ans;
    for(int i=0; i<k; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(gr, vis, 1);
    for(int i=2; i<n+1; i++) {
        if(!vis[i]) {
            ans.push_back(i);
            dfs(gr, vis, i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto&e:ans) cout<<1<<" "<<e<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}