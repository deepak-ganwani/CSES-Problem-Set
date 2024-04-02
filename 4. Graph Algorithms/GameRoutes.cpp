#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], rgr[n+1], dp(n+1,0), deg(n+1,0);
    queue<int> q;
    dp[1]=1;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        rgr[b].push_back(a);
        deg[b]++;
    }
    for(int i=1; i<n+1; i++) {
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()) {
        auto t=q.front();
        q.pop();
        for(auto c:gr[t]) {
            deg[c]--;
            if(!deg[c]) q.push(c);
        }
        for(auto p:rgr[t]) {
            dp[t]=(dp[t]%M+dp[p]%M)%M;
        }
    }
    cout<<dp[n]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}