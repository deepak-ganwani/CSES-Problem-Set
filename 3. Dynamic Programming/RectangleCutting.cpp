#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int a, b; cin>>a>>b;
    vector<vector<int>> dp(a+1, vector<int> (b+1, M));
    for(int i=1; i<a+1; i++) {
        for(int j=1; j<b+1; j++) {
            if(i==j) {
                dp[i][j]=0;
                continue;
            }
            for(int h=1; h<i; h++) {
                dp[i][j]=min(dp[i][j], dp[h][j]+dp[i-h][j]+1);
            }
            for(int v=1; v<j; v++) {
                dp[i][j]=min(dp[i][j], dp[i][v]+dp[i][j-v]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}