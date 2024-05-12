#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e5; //998244353;
vector<int> gr[2*M+2];
int dp[2*M+2];
int diameter[2*M+2];
void calc_dp(int n, int p) {
    int ans=0, leaf_flag=1;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        leaf_flag=0;
        calc_dp(c, n);
        ans=max(ans, dp[c]);
    }
    if(leaf_flag) dp[n]=0;
    else dp[n]=1+ans;
}
void solve(int n, int p){
    int ans=0;
    multiset<int> s;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        solve(c, n);
        ans=max(ans, diameter[c]);
        s.insert(dp[c]);
        if(s.size()>2) s.erase(s.begin());
    }
    if(!s.size()) diameter[n]=0;
    else {
        diameter[n]=1+*(s.begin());
        s.erase(s.begin());
        if(s.size()) diameter[n]+=*(s.begin())+1;
    }
    diameter[n]=max(diameter[n], ans);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    for(int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    calc_dp(1, 0);
    solve(1, 0);
    cout<<diameter[1];
    return !69;
}