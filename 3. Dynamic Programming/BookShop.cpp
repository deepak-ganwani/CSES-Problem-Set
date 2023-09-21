#include <bits/stdc++.h>
using namespace std;
signed main(){
    int n, x; cin>>n>>x;
    vector<int> pr(n,0), pg(n,0);
    for(int i=0; i<n; i++) cin>>pr[i];
    for(int i=0; i<n; i++) cin>>pg[i];
    vector<vector<int>> dp(n, vector<int> (x+1,0));
    for(int i=pr[0]; i<=x; i++) dp[0][i]=pg[0];
    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            if(pr[i]<=j) {
                dp[i][j]=pg[i]+dp[i-1][j-pr[i]];
            }
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }
    cout<<dp[n-1][x]<<endl;
    return !69;
}