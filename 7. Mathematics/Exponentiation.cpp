#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
int power(int a, int b) {
    if(b==0) return 1;
    int t=(power(a, b/2))%M;
    t=(t*t)%M;
    if(b&1) return (t*a)%M;
    return t%M;
}
signed main(){
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        cout<<power(a, b)<<endl;
    }
    return 0;
}