#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
const int N=2e5+5;
int suc[18][N];
inline void solve(){
    int n, q; cin>>n>>q;
    for(int i=2; i<n+1; i++) {
        int a; cin>>a;
        suc[0][i]=a;
    }
    for(int i=1; i<18; i++) {
        for(int j=1; j<n+1; j++) suc[i][j]=suc[i-1][suc[i-1][j]];
    }
    for(int k=0; k<q; k++) {
        int a, b, ans; cin>>a>>b;
        ans=a;
        for(int i=0; i<18; i++) {
            if(b&(1<<i)) ans=suc[i][ans];
        }
        cout<<(ans?ans:-1)<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}