#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
int dp[20][10][2][2]; // Bit, Prev-Digit, Leading 0's, Limit
int f(int i, int pd, int z, int l, string n) {
    if(i==0) return 1;
    if(pd!=-1 && dp[i][pd][z][l]!=-1) return dp[i][pd][z][l];
    int ans=0;
    int num=(n[n.size()-i]-'0');
    int ub=l?num:9;
    for(int j=0; j<=ub; j++) {
        if(j==pd && z==0) continue;
        ans+=f(i-1, j, z&(j==0), l&(j==num), n);
    }
    return dp[i][pd][z][l]=ans;
}
inline void solve(){
    int num1, num2; cin>>num1>>num2;
    string a=to_string(num1-1), b=to_string(num2);
    memset(dp, -1, sizeof(dp));
    int t=f(b.size(), -1, 1, 1, b);
    memset(dp, -1, sizeof(dp));
    int x=f(a.size(), -1, 1, 1, a);
    cout<<t-x<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}