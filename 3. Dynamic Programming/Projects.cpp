#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    vector<vector<int>> v(n);
    vector<int> dp(n+1,0);
    for(int i=0; i<n; i++) {
        int a, b, c; cin>>a>>b>>c;
        v[i]={b, a, c};
    }
    sort(v.begin(), v.end());
    vector<int> s;
    for(int i=1; i<n+1; i++) {
        auto it=lower_bound(s.begin(), s.end(), v[i-1][1])-s.begin();
        dp[i]=max(dp[i-1],v[i-1][2]+dp[it]);
        s.push_back(v[i-1][0]);
    }
    cout<<dp[n]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}