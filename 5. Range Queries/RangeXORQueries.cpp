#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, q; cin>>n>>q;
    vector<int> preXor(n+1, 0);
    for(int i=1; i<=n; i++) {
        int t; cin>>t;
        preXor[i]=t^preXor[i-1];
    }
    for(int i=0; i<q; i++) {
        int l, r; cin>>l>>r;
        cout<<(preXor[r]^preXor[l-1])<<endl;
    }
    return 0;
}