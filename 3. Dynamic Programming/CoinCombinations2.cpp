#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
inline void solve(int tc){
    int n, k; cin>>n>>k;
    vector<int> v(n), dp(k+1,0);
    dp[0]=1;
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    for(int val:v){
        for(int i=1; i<=k; i++){
            if(i-val<0) continue;
            dp[i]+=(dp[i-val]%M);
        }
    }
    cout<<dp[k]%M<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return 0;
}