#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], vis(n+1, 0), cvis(n+1, 0), cyc;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
    }
    function<int(int)> dfs=[&](int nd)->int{
        vis[nd]=1;
        cvis[nd]=1;
        for(int c:gr[nd]) {
            if(cvis[c]) {
                cyc.push_back(c);
                cyc.push_back(nd);
                cvis[nd]=0;
                cvis[c]=0;
                return 1;
            }
            if(!vis[c]) {
                if(dfs(c)) {
                    cyc.push_back(nd);
                    if(cvis[nd]) {
                        cvis[nd]=0;
                        return 1;
                    }
                    cvis[nd]=0;
                    return 0;
                }
            }
            if(cyc.size()) return 0;
        }
        cvis[nd]=0;
        return 0;
    };
    for(int i=1; i<n+1; i++) {
        if(!vis[i]) dfs(i);
        if(cyc.size()) {
            cout<<cyc.size()<<endl;
            reverse(cyc.begin(), cyc.end());
            for(auto&e:cyc) cout<<e<<' ';
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}   
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}