#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
void dfs1(vector<int>* gr, vector<int>& vis, vector<int>& st, int n) {
    vis[n]=1;
    for(auto&e:gr[n]) {
        if(!vis[e]) dfs1(gr, vis, st, e);
    }
    st.push_back(n);
    return;
}
void dfs2(vector<int>* gr, vector<int>& vis, int n) {
    vis[n]=1;
    for(auto&e:gr[n]) {
        if(!vis[e]) dfs2(gr, vis, e);
    }
    return;
}
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], rgr[n+1];
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        rgr[b].push_back(a);
    }
    vector<int> st, vis(n+1, 0);
    for(int i=1; i<n+1; i++) {
        if(!vis[i]) dfs1(gr, vis, st, i);
    }
    reverse(st.begin(), st.end());
    vector<int> vi(n+1, 0);
    int p=-1, c=-1;
    for(int i=0; i<n; i++) {
        if(!vi[st[i]]) {
            dfs2(rgr, vi, st[i]);
            if(p==-1) p=st[i];
            else c=st[i];
        }
    }
    if(c==-1) cout<<"YES"<<endl;
    else {
        cout<<"NO"<<endl;
        cout<<c<<" "<<p<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}