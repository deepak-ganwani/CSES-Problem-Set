#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    vector<int> v(n), dp;
    for(auto&e:v) cin>>e;
    dp.push_back(v[0]);
    for(int i=1; i<n; i++) {
        auto it=lower_bound(dp.begin(), dp.end(), v[i]);
        if(it==dp.end()) dp.push_back(v[i]);
        else *it=v[i];
    }
    cout<<dp.size()<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    solve();
    return !69;
}