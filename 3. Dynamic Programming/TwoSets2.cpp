#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    if((n*(n+1)/2)&1) {
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dp(n, vector<int> (n*(n+1)/4+1, 0));
    dp[0][0]=1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<n*(n+1)/4+1; j++) {
            if(j-i>=0) dp[i][j]=(dp[i-1][j]%M+dp[i-1][j-i]%M)%M;
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n-1][n*(n+1)/4]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}