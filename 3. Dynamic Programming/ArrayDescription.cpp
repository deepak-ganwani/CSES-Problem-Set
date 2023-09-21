#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
signed main(){
    int n, m; cin>>n>>m;
    vector<int> v(n);
    vector<vector<int>>dp(n, vector<int>(m+2,0));
    for(int i=0; i<n; i++) cin>>v[i];
    if(v[0]==0){
        for(int i=1; i<=m; i++) dp[0][i]++;
    }
    else dp[0][v[0]]++;
    for(int i=1; i<n; i++) {
        if(v[i]!=0) {
            dp[i][v[i]]=((dp[i-1][v[i]-1]%M+dp[i-1][v[i]]%M)%M+dp[i-1][v[i]+1])%M;
            continue;
        }
        for(int j=1; j<=m; j++){
            dp[i][j]+=((dp[i-1][j-1]%M+dp[i-1][j]%M)%M+dp[i-1][j+1])%M;
        }
    }
    int ans=0;
    for(int i=1; i<=m; i++) ans+=(dp[n-1][i]%M)%M;
    cout<<ans%M<<endl;
    return !69;
}