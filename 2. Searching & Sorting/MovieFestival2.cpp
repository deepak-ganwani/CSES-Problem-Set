#include <bits/stdc++.h>
using namespace std;
#define int unsigned long int
inline void solve(int tc){
    int n, k, ans=1; cin>>n>>k;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++) {
        int a, b; cin>>a>>b;
        v[i]=make_pair(b, a);
    }
    sort(v.begin(), v.end());
    multiset<int> ms;
    for(int i=0; i<n; i++){
        if(ms.empty()) ms.insert(v[i].first);
        else{
            auto it=ms.upper_bound(v[i].second);
            if(it!=ms.begin()) it--;
            if(v[i].second<*it){
                if(ms.size()<k) {
                    ans++;
                    ms.insert(v[i].first);
                }
                continue;
            }
            ans++;
            ms.erase(it);
            ms.insert(v[i].first);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}