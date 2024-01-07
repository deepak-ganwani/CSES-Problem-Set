#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n; cin>>n;
    map<int, int> m;
    vector<int> dp(n+1, 1);
    for(int i=0; i<n; i++) {
        int t; cin>>t;
        m[t]=i;
    }
    int c=1;
    for(int i=2; i<=n; i++) {
        if(m[i]>m[i-1]) dp[i]=dp[i-1];
        else dp[i]=1+dp[i-1];
        c=max(c, dp[i]);
    }
    cout<<c<<endl;
    return 0;
}