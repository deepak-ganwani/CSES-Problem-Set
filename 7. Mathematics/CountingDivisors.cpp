#include<bits/stdc++.h>
using namespace std;
signed main() {
    int tc; cin>>tc;
    for(int j=0; j<tc; j++) {
        int n, c=0; cin>>n;
        for(int i=1; i*i<=n; i++) {
            if(n%i) continue;
            c+=2;
            if(i*i==n) c--;
        }
        cout<<c<<endl;
    }
    return !69;
}