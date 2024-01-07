#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, s=0; cin>>n;
    vector<int> v(n);
    for(auto&e:v) {
        cin>>e;
        s+=e;
    }
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n, vector<int> (s+1, 0));
    for(int i=0; i<n; i++) dp[i][0]=1;
    dp[0][v[0]]=1;
    set<int> ans;
    ans.insert(v[0]);
    for(int i=1; i<n; i++){
        for(int j=1; j<=s; j++) {
            if(dp[i-1][j]) dp[i][j]=1;
            if(j>=v[i]) dp[i][j]+=dp[i-1][j-v[i]];
            if(dp[i][j]) ans.insert(j); 
        }
    }
    cout<<ans.size()<<endl;
    for(auto e:ans) cout<<e<<" ";
    cout<<endl;
    return !69;
}