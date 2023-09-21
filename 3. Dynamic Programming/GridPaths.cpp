#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, M=1e9+7; cin>>n;
    vector<string> v(n);
    vector<vector<int>> dp(n, vector<int> (n,0));
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=n-1; i>=0; i--){
        if(v[i][n-1]!='*') dp[i][n-1]=1;
        else break;
    }
    for(int i=n-1; i>=0; i--){
        if(v[n-1][i]!='*') dp[n-1][i]=1;
        else break;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            if(v[i][j]=='*') continue;
            dp[i][j]=(dp[i+1][j]%M+dp[i][j+1]%M)%M;
        }
    }
    cout<<dp[0][0]%M<<endl;
    return !69;
}