#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, q; cin>>n>>q;
    vector<int> preSum(n+1,0);
    for(int i=0; i<n; i++){
        int t; cin>>t;
        preSum[i+1]=preSum[i]+t;
    }
    for(int i=0; i<q; i++) {
        int a, b; cin>>a>>b;
        cout<<preSum[b]-preSum[a-1]<<endl;
    }
    return 0;
}