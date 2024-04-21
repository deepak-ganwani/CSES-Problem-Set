#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e18; //998244353;
vector<int> check(int sn, vector<int>* gr, int n) {
    vector<int> vis(n+1, 0);
    queue<int> q;
    q.push(sn);
    while(!q.empty()) {
        int c=q.front();
        q.pop();
        if(vis[c]) continue;
        vis[c]=1;
        for(auto x:gr[c]) {
            if(!vis[x]) q.push(x);
        }
    }
    return vis;
}
inline void solve(){
    int n, m; cin>>n>>m;
    vector<int> lis[m], gr[n+1], rgr[n+1], dist(n+1,M), neg(n+1, 0);
    for(int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c;
        c*=-1;
        lis[i]={a, b, c};
        gr[a].push_back(b);
        rgr[b].push_back(a);
    }
    dist[0]=dist[1]=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int u=lis[j][0], v=lis[j][1], d=lis[j][2];
            if(dist[u]!=M && dist[v]>dist[u]+d) {
                dist[v]=dist[u]+d;
                if(i==n-1) neg[v]=1;
            }

        }
    }
    vector<int> fr=check(1, gr, n+1), br=check(n, rgr, n+1);
    for(int i=1; i<n+1; i++) {
        if(fr[i] && br[i] && neg[i]) {
            cout<<-1<<endl;
            return;
        }
    }
    cout<<-1*dist[n]<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return !69;
}