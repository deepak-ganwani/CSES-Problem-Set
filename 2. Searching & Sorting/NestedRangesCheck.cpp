#include <bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.first==b.first.first) return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}
inline void solve(){
    int n; cin>>n;
    vector<pair<pair<int, int>, int>> vp(n);
    vector<int> a1(n,0), a2(n,0);
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        vp[i]={{a, b}, i};
    }
    sort(vp.begin(), vp.end(), comp);
    int me=vp[0].first.second;
    for(int i=1; i<n; i++) {
        if(vp[i].first.second>me) me=vp[i].first.second;
        else a2[vp[i].second]=1;
    }
    int re=vp[n-1].first.second;
    for(int i=n-2; i>=0; i--) {
        if(vp[i].first.second<re) re=vp[i].first.second;
        else a1[vp[i].second]=1;
    }
    for(auto&e:a1) cout<<e<<' ';
    cout<<endl;
    for(auto&e:a2) cout<<e<<' ';
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}