#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
int ulp(int node, vector<int>& par) { 
    if(node==par[node]) return node;
    return par[node]=ulp(par[node], par);
}
void u_size(int u, int v, vector<int>& par, vector<int>& size) {
    int ulp_u=ulp(u, par);
    int ulp_v=ulp(v, par);
    if(ulp_u==ulp_v) return;
    if(size[ulp_u]<size[ulp_v]) {
        par[ulp_u]=ulp_v;
        size[ulp_v]+=size[ulp_u];
    }
    else {
        par[ulp_v]=ulp_u;
        size[ulp_u]+=size[ulp_v];
    }
}
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> par(n+1), size(n+1, 1);
    iota(par.begin(), par.end(), 0);
    vector<vector<int>> v(m);
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        v[i]={c, a, b};
    }
    sort(v.begin(), v.end());
    int ans=0;
    for(int i=0; i<m; i++) {
        int a=v[i][1], b=v[i][2], c=v[i][0];
        if(ulp(a, par)!=ulp(b, par)) {
            ans+=c;
            u_size(a, b, par, size);
        }
    }
    int c=0;
    for(int i=1; i<n+1; i++) {
        if(ulp(i, par)==i) c++; 
    }
    if(c>1) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}