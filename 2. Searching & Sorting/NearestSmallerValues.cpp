#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n; cin>>n;
    vector<pair<int, int>> v;
    int t; cin>>t;
    v.push_back(make_pair(t, 1));
    cout<<0<<" ";
    for(int i=1; i<n; i++) {
        cin>>t;
        while(!v.empty() && t<=v.back().first) v.pop_back();
        if(v.empty()) cout<<0<<" ";
        else cout<<v.back().second<<" ";
        v.push_back(make_pair(t, i+1));
    }
    return !69;
}