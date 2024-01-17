#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m, q, a, b, c; cin>>n>>m>>q;
    vector<vector<int>> dis(n+1, vector<int> (n+1, 1e16));
    for(int i=0; i<n+1; i++) dis[i][i]=0;
    for(int i=0; i<m; i++) {
        cin>>a>>b>>c;
        if(dis[a][b]<=c) continue;
        dis[a][b]=c;
        dis[b][a]=c;
    }
    for(int k=1; k<n+1; k++) {
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<n+1; j++) {
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=0; i<q; i++) {
        cin>>a>>b;
        if(dis[a][b]==1e16) dis[a][b]=-1;
        cout<<dis[a][b]<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}