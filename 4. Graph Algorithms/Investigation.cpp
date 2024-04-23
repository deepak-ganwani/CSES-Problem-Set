#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
const int INF=2e18;
inline void solve(){
    int n, m; cin>>n>>m;
    vector<pair<int, int>> gr[n+1];
    vector<int> dis(n+1, INF), dp(n+1, 0);
    vector<pair<int, int>> fgNum(n+1, {INF, 0});
    set<pair<int, int>> s;
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        gr[a].push_back({b, c});
    }
    s.insert({0, 1});
    dp[0]=dp[1]=1;
    dis[0]=dis[1]=0;
    fgNum[0]=fgNum[1]={0,0};
    while(!s.empty()) {
        auto [d, nd]=*s.begin();
        s.erase(s.begin());
        if(dis[nd]<d) continue;
        for(auto&[c, w]:gr[nd]) {
            if(d+w<dis[c]) {
                if(dis[c]!=INF) s.erase({dis[c], c});
                fgNum[c].first=fgNum[nd].first+1;
                fgNum[c].second=fgNum[nd].second+1;
                dp[c]=(dp[nd])%M;
                dis[c]=d+w;
                s.insert({dis[c], c});
            }
            else if(d+w==dis[c]) {
                dp[c]=(dp[c]+dp[nd])%M;
                fgNum[c].first=min(fgNum[c].first, fgNum[nd].first+1);
                fgNum[c].second=max(fgNum[c].second, fgNum[nd].second+1);
            }
        }
    }
    cout<<dis[n]<<" "<<dp[n]<<" "<<fgNum[n].first<<" "<<fgNum[n].second<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}