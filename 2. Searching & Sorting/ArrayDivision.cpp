#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
inline void solve(){
    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    int lo=*max_element(v.begin(), v.end()), hi=accumulate(v.begin(), v.end(), 0ll);
    int ans=hi;
    auto check=[&](int mid) {
        int s=0, c=0;
        for(int i=0; i<n; i++) {
            if(s+v[i]>mid) {
                c++;
                s=0;
            }
            s+=v[i];
        }
        c++;
        if(c<=k) return true;
        return false;
    };
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        if(check(mid)) {
            ans=min(ans, mid);
            hi=mid-1;
        }
        else lo=mid+1;
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