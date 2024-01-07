#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ro={0,0,-1,1};
vector<int> co={-1,1,0,0};
void dfs(vector<string>& v, vector<vector<int>>& vis, int i, int j) {
    if(vis[i][j]) return;
    vis[i][j]=1;
    v[i][j]='#';
    for(int t=0; t<4; t++) {
        int r=i+ro[t];
        int c=j+co[t];
        if(r>=0 && r<v.size() && c>=0 && c<v[0].size() && !vis[r][c]) dfs(v, vis, r, c); 
    }
}
inline void solve(){
    int n, m, ans=0; cin>>n>>m;
    vector<string> v(n);
    vector<vector<int>> vis(n, vector<int> (m,0));
    for(auto&e:v) cin>>e;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j]=='#') vis[i][j]=1;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(vis[i][j]) continue;
            dfs(v, vis, i, j);
            ans++;
        }
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