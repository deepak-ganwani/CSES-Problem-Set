#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m, f=0; cin>>n>>m;
    vector<string> gr(n);
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int> (m,0));
    vector<int> ro={-1,1,0,0}, co={0,0,-1,1};
    string ans="";
    pair<int, int>xy;
    for(int i=0; i<n; i++) cin>>gr[i];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(gr[i][j]!='A') continue;
            q.push({i, j});
            vis[i][j]=100;
            break;
        }
    }
    while (!q.empty()) {
        pair<int, int> cor=q.front();
        q.pop();
        if(gr[cor.first][cor.second]=='B') {
            f=1;
            xy=cor;
            break;
        }
        for(int i=0; i<4; i++) {
            int r=cor.first+ro[i];
            int c=cor.second+co[i];
            if(r>=0 && r<n && c>=0 && c<m && gr[r][c]!='#' && !vis[r][c]) {
                q.push({r,c});
                vis[r][c]=(i+1);
            }
        }
    }
    if(!f) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    while(gr[xy.first][xy.second]!='A') {
        if(vis[xy.first][xy.second]==1) {
            ans+='U';
            xy.first++;
        }
        else if(vis[xy.first][xy.second]==2) {
            ans+='D';
            xy.first--;
        }
        else if(vis[xy.first][xy.second]==3) {
            ans+='L';
            xy.second++;
        }
        else {
            ans+='R';
            xy.second--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<"\n"<<ans<<endl;
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}