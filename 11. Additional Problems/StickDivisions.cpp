#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(int tc){
    int n, k, s=0, ans=0; cin>>n>>k;
    vector<int> v(k);
    for(int i=0; i<k; i++){
        cin>>v[i];
        s+=v[i];
    }
    sort(v.rbegin(), v.rend());
    for(int i=0; i<k; i++){
        ans+=s;
        s-=v[i];
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}