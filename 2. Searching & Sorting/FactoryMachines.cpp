#include <bits/stdc++.h>
using namespace std;
#define int long long
bool checkmid(vector<int> v, int t, int m){
    int p=0;
    for(int i=0; i<v.size(); i++) {
        p+=(m/v[i]);
        if(p>=t) return true;
    }
    return false;
}
inline void solve(int tc){
    int n, t, ans=0; cin>>n>>t;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    int lo=0, hi=1e18;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(checkmid(v, t, mid)) {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}