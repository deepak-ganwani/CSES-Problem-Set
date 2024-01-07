#include<bits/stdc++.h>
using namespace std;
signed main(){
    string a, b; cin>>a>>b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    int n=a.size(), m=b.size();
    for(int i=1; i<=n; i++) dp[i][0]=n-i;
    for(int i=1; i<=m; i++) dp[0][i]=m-i;
    if(a[0]!=b[0]) dp[0][0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=1+(min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return !69;
}