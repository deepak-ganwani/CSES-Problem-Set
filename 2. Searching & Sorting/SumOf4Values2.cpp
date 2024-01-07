#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, t; cin>>n>>t;
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    map<int, pair<int, int>> m;
    if(n<4) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    m[v[0]+v[1]]=make_pair(0,1);
    for(int i=2; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int e=t-(v[i]+v[j]);
            if(m.count(e)) {
                cout<<m[e].first+1<<" "<<m[e].second+1<<" "<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
        for(int j=0; j<i; j++) m[v[i]+v[j]]=make_pair(j, i);
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}