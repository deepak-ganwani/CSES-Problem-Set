#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
int dp[1001][1<<10];
int n, m;
void f(int j, int i, int mask, int nmask) {
    if(i==n) {
        dp[j+1][nmask]=(dp[j+1][nmask]+dp[j][mask])%M;
        return;
    }
    if(mask&(1<<i)) f(j, i+1, mask, nmask);
    else {
        f(j, i+1, mask, nmask|(1<<i));
        if(i+1<n && !(mask&(1<<(i+1)))) f(j, i+2, mask, nmask);
    }
}
inline void solve(){
    cin>>n>>m;
    dp[0][0]=1;
    for(int j=0; j<m; j++) {
        for(int mask=0; mask<(1<<n); mask++) {
            if(dp[j][mask]) f(j, 0, mask, 0);
        }
    }
    cout<<dp[m][0];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}