#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
inline void solve(int tc){
    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    map<int, int> m;
    int ans=0, i=0, j=0;
    while(j<n){
        m[v[j]]++;
        while(m[v[j]]>1){
            m[v[i]]--;
            i++;
        }
        ans=max(ans, j-i+1);
        j++;
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}