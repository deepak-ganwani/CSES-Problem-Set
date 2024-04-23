#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
signed main() {
    int t, s=0; cin>>t;
    for(int n=1; n<=t; n++) {
        for(int i=1; i*i<=n; i++) {
            if(n%i) continue;
            (s+=i)%M;
            if(i*i==n) continue;
            (s+=(n/i))%M;
        }
    }
    cout<<s%M<<endl;
    return !69;
}

// This is the TLE Code