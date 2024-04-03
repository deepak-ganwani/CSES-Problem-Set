#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, m, k; cin>>n>>m>>k;
    vector<pair<int, int>> gr[n+1];
    multiset<int> ans[n+1];
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        gr[a].push_back({b, c});
    }
    multiset<vector<int>> s; // cost, node
    ans[1].insert(0);
    s.insert({0,1});
    while (!s.empty())
    {
        auto t=*s.begin();
        s.erase(s.begin());
        if(t[0]>*(ans[t[1]]).rbegin()) continue;
        for(auto c:gr[t[1]]) {
            int v=c.second+t[0];
            if(ans[c.first].size()<k) {
                ans[c.first].insert(v);
                s.insert({v, c.first});
            } else if(*(ans[c.first].rbegin())>v) {
                ans[c.first].erase(prev(ans[c.first].end()));
                ans[c.first].insert(v);
                s.insert({v, c.first});
            }
        }
    }
    for(auto&e:ans[n]) cout<<e<<' ';
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}