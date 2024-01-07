#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.first==b.first.first) return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}
inline void solve(){
    int n; cin>>n;
    set<pair<int, int>> e;
    vector<int> x(n,0), y(n,0), e(n,0);
    vector<pair<pair<int, int>, int>> vp(n);
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        vp[i]={{a, b}, i};
        e[i]=b;
    }
    sort(vp.begin(), vp.end(), comp);
    sort(e.begin(), e.end());
    for(int i=0; i<n; i++) cout<<vp[i].first.first<<" "<<vp[i].first.second<<endl;
    for(int i=0; i<n; i++) {
        auto el=e.lower_bound({vp[i].first.second,0});
        if(el!=e.end()) y[vp[i].second]=1;
        e.insert({vp[i].first.second, vp[i].second});
    }
    for(int i=0; i<n; i++) {
        
    }
    for(auto&e:x) cout<<e<<" ";
    cout<<endl;
    for(auto&e:y) cout<<e<<" ";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}