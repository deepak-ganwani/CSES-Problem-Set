#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, k; cin>>n>>k;
    vector<int> v(k);
    int ans=0;
    for(auto&e:v) cin>>e;
    for(int i=1; i<(1<<k); i++) {
        int c=0, p=n;
        for(int j=0; j<k; j++) {
            if(i&(1<<j)) {
                c++;
                p/=v[j];
            }
        }
        if(c&1) ans+=p;
        else ans-=p;
    }
    cout<<ans;
    return !69;
}