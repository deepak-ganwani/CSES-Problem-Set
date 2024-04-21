#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    string a, b; cin>>a>>b;
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    for(int i=0; i<a.size()+1; i++) dp[i][0]=i;
    for(int j=0; j<b.size()+1; j++) dp[0][j]=j;
    for(int i=1; i<a.size()+1; i++) {
        for(int j=1; j<b.size()+1; j++) {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}