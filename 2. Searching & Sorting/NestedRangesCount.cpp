#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.first==b.first.first) return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}
inline void solve(){
    int n; cin>>n;
    vector<pair<pair<int, int>, int>> vp(n);
    vector<int> a1(n,0), a2(n,0);
    os<pair<int, int>> e1, e2;
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        vp[i]={{a, b}, i};
    }
    sort(vp.begin(), vp.end(), comp);
    e1.insert({vp[0].first.second,0});
    for(int i=1; i<n; i++) {
        e1.insert({vp[i].first.second, -1*i});
        a2[vp[i].second]=e1.size()-e1.order_of_key({vp[i].first.second,-1*i})-1;
    }
    e2.insert({vp[n-1].first.second,-1*(n-1)});
    for(int i=n-2; i>=0; i--) {
        e2.insert({vp[i].first.second, -1*i});
        a1[vp[i].second]=e2.order_of_key({vp[i].first.second, -1*i});
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