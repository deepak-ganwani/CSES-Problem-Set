#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n; cin>>n;
    int lo=1, hi=n*n, ans=1;
    function<int(int)> check=[&](int mid)->int{
        int c=0;
        for(int i=1; i<=n; i++) c+=min(n, mid/i);
        return c;
    };
    while(lo<=hi) {
        int mid=lo+(hi-lo)/2;
        int c=check(mid);
        if(c<(n*n+1)>>1) lo=mid+1;
        else {
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}