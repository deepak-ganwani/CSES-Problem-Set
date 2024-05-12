#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> dp(1<<n, {1e9, 1e9});
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    dp[0]={1,0};
    for(int i=1; i<(1<<n); i++) {
        for(int j=0; j<20; j++) {
            if(!(i&(1<<j))) continue;
            int rem=i-(1<<j);
            int req=dp[rem].first+(dp[rem].second+v[j]>m);
            int w=(dp[rem].second+v[j]>m?v[j]:dp[rem].second+v[j]);
            if(dp[i].first>req) dp[i]={req, w};
            else if(dp[i].first==req) dp[i].second=min(dp[i].second, w);
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}