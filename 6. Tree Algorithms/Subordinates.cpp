#include <bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int i, vector<int>* g, vector<int>& ans){
    for(int child:g[i]){
        dfs(child, g, ans);
        ans[i]+=ans[child];
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, a; cin>>n;
    vector<int> g[n+1], ans(n+1,1);
    for(int i=2; i<n+1; i++) {
        cin>>a;
        g[a].push_back(i);
    }
    dfs(1,g,ans);
    for(int i=1; i<n+1; i++) cout<<ans[i]-1<<" ";
    cout<<endl;
    return 0;
}