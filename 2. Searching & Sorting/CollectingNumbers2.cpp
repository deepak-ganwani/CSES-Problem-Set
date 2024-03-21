#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define debug(...) 69
#else
#include "../../algo/debug.h"
#endif
#define int long long
inline void solve(){
    int n, q; cin>>n>>q;
    vector<int> v(n+2), inv(n+2, 0);
    iota(inv.begin(), inv.end(), 0);
    for(int i=1; i<n+1; i++) {
        int t; cin>>t;
        v[i]=t;
        inv[t]=i;
    }
    int ans=1;
    for(int i=1; i<n+1; i++) if(inv[i]<inv[i-1]) {
        ans++;
    }
    for(int i=0; i<q; i++) {
        int a, b; cin>>a>>b;
        set<pair<int, int>> ch;
        ch.insert({v[a], v[a]+1});
        ch.insert({v[a]-1, v[a]});
        ch.insert({v[b], v[b]+1});
        ch.insert({v[b]-1, v[b]});
        for(auto p:ch) {
            if(inv[p.first]>inv[p.second]) ans--;
        }
        int ac=a, bc=b;
        swap(v[a], v[b]);
        inv[v[a]]=a;
        inv[v[b]]=b;
        for(auto p:ch) {
            if(inv[p.first]>inv[p.second]) ans++;
        }
        cout<<ans<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}