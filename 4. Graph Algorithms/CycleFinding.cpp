#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=LLONG_MAX; //998244353;
inline void solve(){
    int n, m, f=0; cin>>n>>m;
    vector<vector<int>> ed;
    vector<int> dis(n+1, 0), neg(n+1,0);
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        ed.push_back({a,b,c});
    }
    for(int i=0; i<n; i++) for(auto&e:ed) {
        if(dis[e[0]]==M) continue;
        if(dis[e[0]]+e[2]<dis[e[1]]) dis[e[1]]=dis[e[0]]+e[2];
    }
    for(int i=0; i<n; i++) for(auto&e:ed) {
        if(dis[e[0]]==M) continue;
        if(dis[e[0]]+e[2]<dis[e[1]]) {
            dis[e[1]]=dis[e[0]]+e[2];
            f=1;
            neg[e[1]]=e[0];
        }
    }
    if(!f) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int x=0;
    for(int i=1; i<n+1; i++) {
        if(neg[i]) {
            x=i;
            break;
        }
    }
    set<int> s;
    vector<int> ans;
    while(true) {
        if(s.find(x)==s.end()) {
            s.insert(x);
            ans.push_back(x);
            x=neg[x];
        }
        else break;
    }
    ans.push_back(x);
    reverse(ans.begin(), ans.end());
    s.clear();
    for(auto&e:ans) {
        cout<<e<<' ';
        if(s.find(e)!=s.end()) break;
        s.insert(e);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}