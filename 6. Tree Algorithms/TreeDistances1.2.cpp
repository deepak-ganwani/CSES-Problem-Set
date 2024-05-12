#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=2e5+1; //998244353;
vector<int> gr[M];
int ans[M];
int calc_depth(int n, int p) {
    for(auto&c:gr[n]) {
        if(c==p) continue;
        ans[n]=max(ans[n], 1+calc_depth(c, n));
    }
    return ans[n];
}
void solve(int n, int p, int par_ans) {
    vector<int> preMax, sufMax;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        preMax.push_back(ans[c]);
        sufMax.push_back(ans[c]);
    }
    for(int i=1; i<preMax.size(); i++) preMax[i]=max(preMax[i], preMax[i-1]);
    for(int i=sufMax.size()-2; i>=0; i--) sufMax[i]=max(sufMax[i], sufMax[i+1]);
    int i=0;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        int a=(i==0?INT_MIN:preMax[i-1]);
        int b=(i==preMax.size()-1?INT_MIN:sufMax[i+1]);
        solve(c, n, 1+max({par_ans, a, b}));
        i++;
    }
    ans[n]=max(ans[n], 1+par_ans);
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
    calc_depth(1, 0);
    solve(1,0,-1);
    for(int i=1; i<n+1; i++) cout<<ans[i]<<' ';
    return !69;
}