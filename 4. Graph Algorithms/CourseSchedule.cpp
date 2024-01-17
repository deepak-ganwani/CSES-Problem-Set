#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> ans, deg(n+1,0), gr[n+1];
    queue<int> q;
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        deg[b]++;
    }
    for(int i=1; i<n+1; i++) {
        if(!deg[i]) {
            q.push(i);
            ans.push_back(i);
        }
    }
    while(!q.empty()) {
        int t=q.front();
        q.pop();
        for(int i:gr[t]) {
            deg[i]--;
            if(!deg[i]) {
                ans.push_back(i);
                q.push(i);
            }
        }
    }
    if(ans.size()==n) {
        for(auto&e:ans) cout<<e<<' ';
        cout<<endl;
        return;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}