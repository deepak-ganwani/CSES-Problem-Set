#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ans;
int sn=0, en=0, f=0;
void getTrack(vector<vector<int>>& gr, vector<int>& vis, int n, int sn) {
    ans.push_back(n);
    if(n==sn || vis[n]==-1) return;
    getTrack(gr, vis, vis[n], sn);
}
void dfs(vector<vector<int>>& gr, vector<int>& vis, int n, int p) {
    vis[n]=p;
    for(int c:gr[n]) {
        if(f) return;
        if(!vis[c]) dfs(gr, vis, c, n);
        else if(vis[c] && c!=p) {
            sn=c;
            en=n;
            f=1;
            return;
        }
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
    for(int i=0; i<n; i++) {
        if(!vis[i]) dfs(gr, vis, i, -1);
    }
    if(f) {
        ans.push_back(sn);
        getTrack(gr, vis, en, sn);
        cout<<ans.size()<<endl;
        for(auto&e:ans) cout<<e<<" ";
        return;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}