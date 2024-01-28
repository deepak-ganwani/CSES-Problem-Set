#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(...) 69
#else
#include "../../algo/debug.h"
#endif
#define int long long
inline void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> gr[n+1];
    vector<int> vis(n+1,0);
    set<pair<pair<int, int>, int>> s; // val, max, node 
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        gr[a].push_back({b, c});
    }
    s.insert({{0, 0}, 1});
    while(!s.empty()) {
        pair<pair<int, int>, int> t=*(s.begin());
        s.erase(s.begin());
        if(vis[t.second]) continue;
        vis[t.second]=1;
        if(t.second==n) {
            cout<<t.first.first<<endl;
            break;
        }
        for(auto c:gr[t.second]) {
            if(vis[c.first]) continue;
            if(c.second>t.first.second) {
                int x=c.second/2+t.first.second-t.first.second/2;
                s.insert({{x+t.first.first, c.second}, c.first});
            }
            else s.insert({{t.first.first+c.second, t.first.second},c.first});
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}