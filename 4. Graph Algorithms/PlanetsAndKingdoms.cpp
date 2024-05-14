#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
void dfs1(vector<int>* gr, vector<int>&ord, vector<int>&vis, int n) {
    vis[n]=1;
    for(auto&e:gr[n]) {
        if(!vis[e]) dfs1(gr, ord, vis, e);
    }
    ord.push_back(n);
    return;
}
void dfs2(vector<int>* rgr, vector<int>&ans, int x, int n) {
    ans[n]=x;
    for(auto&e:rgr[n]) {
        if(!ans[e]) dfs2(rgr, ans, x, e);
    }
}
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], rgr[n+1];
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        rgr[b].push_back(a);
    }
    vector<int> ord, vis(n+1, 0), ans(n+1, 0);
    for(int i=1; i<n+1; i++) {
        if(!vis[i]) dfs1(gr, ord, vis, i);
    }
    int x=0;
    reverse(ord.begin(), ord.end());
    for(auto&e:ord) {
        if(!ans[e]) {
            x++;
            dfs2(rgr, ans, x, e);
        }
    }
    cout<<x<<endl;
    for(int i=1; i<n+1; i++) cout<<ans[i]<<' ';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}