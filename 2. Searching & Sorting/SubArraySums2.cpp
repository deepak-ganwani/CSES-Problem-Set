#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
inline void solve(){
    int n, k, ans=0, s=0; cin>>n>>k;
    map<int, int> m;
    m[0]=1;
    for(int i=0; i<n; i++) {
        int t; cin>>t;
        s+=t;
        ans+=m[s-k];
        m[s]++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}