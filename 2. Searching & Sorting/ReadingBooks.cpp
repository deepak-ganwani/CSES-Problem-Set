#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
inline void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    sort(v.begin(), v.end());
    int s=0;
    for(int i=0; i<n-1; i++) {
        s+=v[i];
    }
    if(s<=v[n-1]) cout<<2*v[n-1]<<endl;
    else {
        cout<<s+v[n-1]<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}