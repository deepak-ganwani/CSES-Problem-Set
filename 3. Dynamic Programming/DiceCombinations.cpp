//Link: https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back
int M=1e9+7;

vi dp(1e6+1,-1);

int numberOfWays(int n) {
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n]%M;
    dp[n]=0;
    rep(i,1,7) dp[n]+=(numberOfWays(n-i))%M;
    dp[n]=dp[n]%M;
    return dp[n]%M;
}

void solve(int tc){
    int n;
    cin>>n;
    dp[0]=1;
    cout<<numberOfWays(n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t=1;
    // cin>>t;
    rep(tc,0,t)
    {
        // cout<<"Case #"<<tc+1<<": ";
        solve(tc);
    }
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/