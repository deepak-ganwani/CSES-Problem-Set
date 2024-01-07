#include<bits/stdc++.h>
using namespace std;
#define int long long
int power(int a, int b, int M) {
    if(b==0) return 1;
    int t=(power(a, b/2, M))%M;
    t=(t*t)%M;
    if(b&1) return (t*a)%M;
    return t%M;
}
signed main(){
    int n; cin>>n;
    int M=1e9+7;
    for(int i=0; i<n; i++) {
        int a, b, c; cin>>a>>b>>c;
        cout<<power(a, power(b, c, M-1), M)<<endl;
    }
    return 0;
}
// Using Fermats little theorem