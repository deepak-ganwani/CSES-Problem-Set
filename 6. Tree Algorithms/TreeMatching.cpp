// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    vector<int> adj[n+1];
    vector<vector<int>> dp(n+1, {0,0});
    for(int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<void(int, int)> dfs=[&](int n, int p) {
        for(auto c:adj[n]) {
            if(c!=p) {
                dfs(c, n);
                dp[n][0]+=max(dp[c][0], dp[c][1]);
            }
        }
        for(auto c:adj[n]) {
            if(c!=p) {
                dp[n][1]=max(dp[n][1], dp[c][0]+1+dp[n][0]-max(dp[c][0], dp[c][1]));
            }
        }
    };
    dfs(1,0);
    cout<<max(dp[1][0], dp[1][1])<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}