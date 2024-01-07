#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
inline void solve(int tc){
    int n, k; cin>>n>>k;
    vector<int> c(n);
    for(int i=0; i<n; i++) cin>>c[i];
    vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
    for(int i=0; i<=n; i++) dp[i][0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if(i>1) dp[i][j]=dp[i-1][j]%M;
            if(j-c[i-1]>=0) dp[i][j]=(dp[i][j]%M+dp[i][j-c[i-1]]%M)%M;
        }
    }
    cout<<dp[n][k]%M<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return 0;
}