#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=2e5+2; //998244353;
vector<int> gr[M];
int sz[M];
int ans[M];
void calc_depth(int n, int p) {
    sz[n]=1;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        calc_depth(c, n);
        ans[n]+=sz[c]+ans[c];
        sz[n]+=sz[c];
    }
}
void solve(int n, int p, int par_sum, int tot_nodes){
    ans[n]+=par_sum+(tot_nodes-sz[n]);
    for(auto&c:gr[n]) {
        if(c==p) continue;
        solve(c, n, ans[n]-ans[c]-sz[c], tot_nodes);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin>>n;
    for(int i=1; i<n; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    calc_depth(1, 0);
    solve(1,0,0,n);
    for(int i=1; i<n+1; i++) cout<<ans[i]<<' ';
    return !69;
}