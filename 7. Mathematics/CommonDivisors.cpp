#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> f(1e6+1,0), mul(1e6+1,0);
inline void solve(){
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        f[x]++;
    }
    for(int i=1; i<1e6+1; i++) {
        for(int j=i; j<1e6+1; j+=i) mul[i]+=f[j];
    }
    for(int i=1e6; i>=1; i--) {
        if(mul[i]>1) {
            cout<<i<<endl;
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}