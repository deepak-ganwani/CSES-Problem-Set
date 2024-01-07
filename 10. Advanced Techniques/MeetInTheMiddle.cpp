#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
vector<int> a;
map<int, int> m;
void func(vector<int>& v, int i, int s, int f) {
    if(i==v.size()) {
        if(f) a.push_back(s);
        else m[s]++;
        return;
    }
    func(v, i+1, s, f);
    func(v, i+1, s+v[i], f);
}
inline void solve(){
    int n, x, ans=0; cin>>n>>x;
    vector<int> v1(n/2), v2(n-n/2);
    for(int i=0; i<n/2; i++) cin>>v1[i];
    for(int i=0; i<(n-n/2); i++) cin>>v2[i];
    func(v1, 0, 0, 1);
    func(v2, 0, 0, 0);
    for(int i=0; i<a.size(); i++) {
        ans+=m[x-a[i]];
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}