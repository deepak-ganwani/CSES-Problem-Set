#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, k; cin>>n>>k;
    vector<pair<int, int>> v(n+1);
    vector<int> vo(n+1);
    map<int, pair<int, int>> m;
    for(int i=1; i<=n; i++){
        int t; cin>>t;
        v[i]=make_pair(t, i);
        vo[i]=t;
    } 
    sort(v.begin(), v.end());
    for(int i=1; i<=n; i++) {
        m[i]=make_pair(v[i].second, (i<n?v[i+1].second:0));
    }
    int ans=1;
    for(int i=1; i<n; i++) {
        if(v[i].second<v[i+1].second) continue;
        ans++; 
    }
    for(int i=0; i<k; i++) {
        int a, b; cin>>a>>b;
        if(vo[a]-1>0) {
            if(m[vo[a]-1].second>b)
        }
        swap(vo[a], vo[b]);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}