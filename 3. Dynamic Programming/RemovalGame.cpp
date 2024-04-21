#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n,0));
    for(auto&e:v) cin>>e;
    int s=accumulate(v.begin(), v.end(), 0ll);
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j<n; j++) {
            if(i==j) dp[i][j]=v[i];
            else {
                dp[i][j]=max(v[i]-dp[i+1][j], v[j]-dp[i][j-1]);
            }
        }
    }
    cout<<((s+dp[0][n-1])>>1)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}