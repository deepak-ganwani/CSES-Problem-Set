#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    vector<int> gr[n+1];
    for(int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    queue<int> q;
    vector<int> vis(n+1, 0);
    q.push(1);
    int last=1;
    while(!q.empty()) {
        int nd=q.front();
        q.pop();
        vis[nd]=1;
        last=nd;
        for(auto&e:gr[nd]) {
            if(!vis[e]) q.push(e);
        }
    }
    vector<int> dis(n+1, INT_MAX);
    q.push(last);
    int ls=last;
    int d=1;
    while(!q.empty()) {
        int nd=q.front();
        q.pop();
        ls=nd;
        for(auto&e:gr[nd]) {
            if(dis[e]==INT_MAX) {
                dis[e]=d;
                q.push(e);
            }
        }
        d++;
    }
    dis[last]=dis[ls];
    for(int i=1; i<n+1; i++) cout<<dis[i]<<" ";
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}