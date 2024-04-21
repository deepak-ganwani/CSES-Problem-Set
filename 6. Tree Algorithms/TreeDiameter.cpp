// WHY DO WE FALL? 
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
    function<pair<int, int>(int)> bfs=[&](int nd)->pair<int, int>{
        queue<vector<int>> q;
        q.push({0, nd, 0});
        pair<int, int> ans={0,0};
        while(!q.empty()) {
            auto t=q.front();
            q.pop();
            if(t[0]>=ans.first) ans={t[0], t[1]};
            for(auto&c:gr[t[1]]) {
                if(c==t[2]) continue;
                q.push({1+t[0], c, t[1]});
            }
        }
        return ans;
    };
    pair<int, int> end1=bfs(1);
    pair<int, int> ans=bfs(end1.second);
    cout<<ans.first<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}