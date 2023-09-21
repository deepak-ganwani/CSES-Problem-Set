#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(int tc){
    int n; cin>>n;
    multiset<int> s;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++){
        if(s.empty()) s.insert(v[i]);
        else{
            auto it=s.upper_bound(v[i]);
            if(it!=s.end()) s.erase(it);
            s.insert(v[i]);
        }
    }
    cout<<s.size()<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}