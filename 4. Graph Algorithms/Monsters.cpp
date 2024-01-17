#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void solve(){
    int n, m; cin>>n>>m;
    vector<string> gr(n);
    vector<vector<int>> dis(n, vector<int> (m,INT_MAX));
    vector<vector<int>> vis(n, vector<int> (m,0));
    vector<vector<int>> prev(n, vector<int> (m,-1));
    vector<int> ro={-1,0,1,0}, co={0,-1,0,1}; // U L D R
    pair<int, int> si={-1,-1}, ei={-1,-1};
    queue<pair<pair<int, int>, int>> q;
    pair<int, int> cor;
    int d, x;
    string ans="";
    for(auto&e:gr) cin>>e;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(gr[i][j]=='M') {
                q.push({{i,j},0});
            }
            else if(gr[i][j]=='A') {
                si={i,j};
            }
        }
    }
    
    while(!q.empty()) {
        cor=q.front().first;
        d=q.front().second;
        q.pop();
        if(dis[cor.first][cor.second]<=d) continue;
        dis[cor.first][cor.second]=d;
        for(int i=0; i<4; i++) {
            int r=cor.first+ro[i];
            int c=cor.second+co[i];
            if(r>=0 && r<n && c>=0 && c<m && gr[r][c]!='#' && dis[r][c]>d+1) {
                q.push({{r,c},d+1});
            }
        }
    }
    vis[si.first][si.second]=1;
    q.push({{si.first, si.second},0});
    while(!q.empty()) {
        cor=q.front().first;
        d=q.front().second;
        q.pop();
        if(dis[cor.first][cor.second]<=d) continue;
        if(cor.first==0 || cor.first==n-1 || cor.second==0 || cor.second==m-1) {
            ei=cor;
            break;
        }
        for(int i=0; i<4; i++) {
            int r=cor.first+ro[i];
            int c=cor.second+co[i];
            if(r>=0 && r<n && c>=0 && c<m && gr[r][c]!='#' && !vis[r][c]) {
                prev[r][c]=i;
                vis[r][c]=1;
                q.push({{r,c},d+1});
            }
        }
    }
    if(ei.first==-1) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    while(ei!=si) {
        x=prev[ei.first][ei.second];
        if(x==0) ans+='U';
        else if(x==1) ans+='L';
        else if(x==2) ans+='D';
        else ans+='R';
        ei.first-=ro[x];
        ei.second-=co[x];
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}