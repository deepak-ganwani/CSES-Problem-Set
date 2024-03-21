#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
inline void solve(){
    int n; cin>>n;
    int k=1;
    os<int> s;
    for(int i=1; i<n+1; i++) s.insert(i);
    int st=0;
    while(s.size()) {
        int i=(st+k)%s.size();
        int v=*s.find_by_order(i);
        cout<<v<<' ';
        s.erase(s.find_by_order(i));
        st=i;
    }
    cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
    return !69;
}