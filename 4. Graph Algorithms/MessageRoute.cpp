#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m, f=0; cin>>n>>m;
    vector<vector<int>> gr(n+1);
    vector<int> vis(n+1,0), ans;
    queue<int> q;
    q.push(1);
    for(int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==n) {
            f=1;
            break;
        }
        for(int child:gr[node]) {
            if(!vis[child]) {
                vis[child]=node;
                q.push(child);
            }
        }
    }
    if(!f) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    while(n!=1) {
        ans.push_back(n);
        n=vis[n];
    }
    cout<<ans.size()+1<<"\n1 ";
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}