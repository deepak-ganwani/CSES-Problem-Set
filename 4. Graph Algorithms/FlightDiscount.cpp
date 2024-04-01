#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> gr[n+1];
    vector<vector<int>> vis(n+1, {0,0});
    set<vector<int>> s; // cost, dis, pos
    s.insert({0,0,1});
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        gr[a].push_back({b, c});
    }
    while(s.size()) {
        auto top=*s.begin();
        s.erase(s.begin());
        int co=top[0], us=top[1], po=top[2];
        if(vis[po][us]) continue;
        vis[po][us]=1;
        if(po==n) {
            cout<<co<<endl;
            return;
        }
        for(auto [c,w]:gr[po]) {
            s.insert({co+w, us, c});
            if(!us) s.insert({co+w/2, 1, c});
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