#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], rgr[n+1], v(n);
    for(auto&e:v) cin>>e;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}