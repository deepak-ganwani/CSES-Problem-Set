#include <bits/stdc++.h>
using namespace std;
#define int 		long long
inline void solve(int tc){
    int n, c=0, ans=0; cin>>n;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++) cin>>vp[i].first>>vp[i].second;
    sort(vp.begin(), vp.end());
    for(int i=0; i<n; i++){
        c+=vp[i].first;
        ans+=(vp[i].second-c);
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}