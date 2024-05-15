#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
const int M2INV=500000004;
int f(int s, int e) {
    return (((((e+s)%M)*((e-s+1)%M))%M)*M2INV)%M;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    int s=0;
    int cur=1;
    while(cur<=t) {
        int x=t/cur;
        int nx=t/x;
        s=(s+(x*f(cur, nx))%M)%M;
        cur=nx+1;
    }
    cout<<s;
    return !69;
}