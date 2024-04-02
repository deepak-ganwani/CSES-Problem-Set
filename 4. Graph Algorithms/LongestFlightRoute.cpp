// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> gr[n+1], rgr[n+1], deg(n+1, 0), dp(n+1, 0), par(n+1, -1);
    queue<int> q;
    dp[1]=1;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        deg[b]++;
        rgr[b].push_back(a);
    }
    for(int i=1; i<n+1; i++) {
        if(!deg[i]) q.push(i);
    }
    while(!q.empty()) {
        auto t=q.front();
        q.pop();
        for(auto&c:gr[t]) {
            deg[c]--;
            if(!deg[c]) q.push(c);
        }
        for(auto&p:rgr[t]) {
            if(dp[p]!=0 && 1+dp[p]>dp[t]) {
                dp[t]=1+dp[p];
                par[t]=p;
            }
        }
    }
    if(!dp[n]) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<dp[n]<<endl;
    int x=n;
    vector<int> ans;
    while(x!=-1) {
        ans.push_back(x);
        x=par[x];
    }
    reverse(ans.begin(), ans.end());
    for(auto&e:ans) cout<<e<<' ';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}