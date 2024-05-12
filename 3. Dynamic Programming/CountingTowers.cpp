#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
const int N=1e6+7;
int dp[N][2];
inline void solve(){
    int n; cin>>n;
    dp[n][0]=1;
    dp[n][1]=1;
    for(int i=n-1; i>=0; i--) {
        dp[i][0]=(2*dp[i+1][0]+dp[i+1][1])%M;
        dp[i][1]=(4*dp[i+1][1]+dp[i+1][0])%M;
    }
    cout<<(dp[1][0]+dp[1][1])%M<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    for(int i=0; i<t; i++) solve();
    return !69;
}