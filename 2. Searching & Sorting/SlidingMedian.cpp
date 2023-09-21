#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
inline void solve(int tc){
    int n, k; cin>>n>>k;    
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    ordered_set<pair<int, int>> o;
    for(int i=0; i<k; i++) o.insert({v[i], i});
    for(int i=0; i<n-k+1; i++){
        cout<< o.find_by_order((k-1)/2)->first <<" ";
        o.erase({v[i],i});
        o.insert({v[i+k], i+k});
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}