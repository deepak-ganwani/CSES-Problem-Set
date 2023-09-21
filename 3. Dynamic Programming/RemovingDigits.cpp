#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, c=0; cin>>n;
    vector<int> dp(n+1, 2e18);
    dp[0]=0;
    for(int i=1; i<=n; i++){
        int temp=i;
        while(temp){
            if(temp%10) dp[i]=min(dp[i], 1+dp[i-temp%10]);
            temp/=10;
        }
    }
    cout<<dp[n]<<endl;
    return !69;
}