#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m, a, b, c; cin>>n>>m;
    vector<pair<int, int>> gr[n+1];
    vector<int> ans(n+1, INT64_MAX);
    set<pair<int, int>> s;
    for(int i=0; i<m; i++) {
        cin>>a>>b>>c;
        gr[a].push_back({b, c});
    }
    s.insert({0,1});
    while (!s.empty()) {
        pair<int, int> t=*(s.begin());
        s.erase(s.begin());
        if(ans[t.second]<t.first) continue;
        ans[t.second]=t.first;
        for(auto i:gr[t.second]) {
            s.insert({i.second+t.first, i.first});
        }
    }
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}