#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    if(k==1) {
        while(n--) cout<<0<<' ';
        return;
    }
    if(k==2) {
        for(int i=1; i<n; i++) cout<<abs(v[i]-v[i-1])<<' ';
        return;
    }
    set<pair<int, int>> ls, rs;
    int lsm=0, rsm=0;
    for(int i=0; i<k; i++) {
        rs.insert({v[i], i});
        rsm+=v[i];
    }
    for(int i=0; i<(k+1)/2; i++) {
        auto t=*rs.begin();
        rs.erase(rs.begin());
        ls.insert(t);
        rsm-=t.first;
        lsm+=t.first;
    }
    for(int i=0; i<n-k+1; i++) {
        auto m=(*ls.rbegin()).first;
        cout<<ls.size()*m-lsm+rsm-rs.size()*m<<' ';
        if(ls.count({v[i], i})) {
            lsm-=v[i];
            ls.erase(ls.find({v[i], i}));
        } else {
            rsm-=v[i];
            rs.erase(rs.find({v[i], i}));
        }
        if(v[i+k]<m) {
            lsm+=v[i+k];
            ls.insert({v[i+k], i+k});
        } else {
            rsm+=v[i+k];
            rs.insert({v[i+k], i+k});
        }
        while(ls.size()<(k+1)/2) {
            auto el=*rs.begin();
            rsm-=el.first;
            lsm+=el.first;
            ls.insert(el);
            rs.erase(rs.begin());
        }
        while(ls.size()>(k+1)/2) {
            auto el=*ls.rbegin();
            rsm+=el.first;
            lsm-=el.first;
            rs.insert(el);
            ls.erase(el);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}