#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n, q; cin>>n>>q;
    int suc[n+1][30];
    for(int i=0; i<n; i++) {
        int a; cin>>a;
        suc[i+1][0]=a;
    }
    for(int j=1; j<30; j++) {
        for(int i=1; i<n+1; i++) suc[i][j]=suc[suc[i][j-1]][j-1];
    }
    for(int k=0; k<q; k++) {
        int a, b, ans; cin>>a>>b;
        ans=a;
        for(int i=0; i<30; i++) {
            if(b&(1<<i)) ans=suc[ans][i];
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