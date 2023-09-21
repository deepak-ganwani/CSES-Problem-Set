#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,x,y) for(int i=x; i<y; i++)
#define endl '\n'
inline void solve(int tc){
    int n, k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    map<int, int> m;
    int ans=0, i=0, j=0;
    while(i<n){
        m[v[j]]++;
        while (m.size()>k)
        {
            ans+=j-i;
            m[v[i]]--;
            if(m[v[i]]==0) m.erase(v[i]);
            i++;
        }
        if(j<n)j++;
        else {
            ans+=j-i;
            i++;
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