// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n; 
    vector<int> gr[n+1], dis(n+1, 0);
    for(int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    function<int(int)> bfs=[&](int nd)->int{
        queue<vector<int>> q;
        q.push({0, nd, 0});
        int ans=0;
        while(!q.empty()) {
            auto t=q.front();
            q.pop();
            dis[t[1]]=max(dis[t[1]], t[0]);
            ans=t[1];
            for(auto&c:gr[t[1]]) {
                if(c==t[2]) continue;
                q.push({1+t[0], c, t[1]});
            }
        }
        return ans;
    };
    int end1=bfs(1);
    int end2=bfs(end1);
    bfs(end2);
    for(int i=1; i<n+1; i++) cout<<dis[i]<<" ";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}