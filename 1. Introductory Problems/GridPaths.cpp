#include <bits/stdc++.h>
using namespace std;
#define int long long
string s; 
int dx[4]={0,-1,0,1}, dy[4]={-1,0,1,0}, vis[7][7];
bool isVal(int x, int y) {
    return (x+y>=0 && x+y<7);
}
int count(int x, int y, int pos) {
    if(pos==48) return (x==6&&y==0);
    if(x==6&&y==0) return 0;
    if(vis[x][y]) return 0;
    vector<bool> v(4, -1);
    for(int i=0; i<4; i++) {
        if(isVal(x, dx[i]) && isVal(y, dy[i])) {
            v[i]=vis[x+dx[i]][y+dy[i]];
        }
    }
    if(!v[1] && !v[3] && v[0] && v[2]) return 0;
    if(!v[0] && !v[2] && v[1] && v[3]) return 0;
    if(isVal(x,-1)&&isVal(y,-1)&&vis[x-1][y-1]&&!v[0]&&!v[1]) return 0;
    if(isVal(x,-1)&&isVal(y,1)&&vis[x-1][y+1]&&!v[1]&&!v[2]) return 0;
    if(isVal(x,1)&&isVal(y,1)&&vis[x+1][y+1]&&!v[2]&&!v[3]) return 0;
    if(isVal(x,1)&&isVal(y,-1)&&vis[x+1][y-1]&&!v[3]&&!v[0]) return 0;
    vis[x][y]=1;
    int ans=0;
    if(s[pos]=='?') {
        for(int i=0; i<4; i++) {
            if(isVal(x, dx[i])&&isVal(y, dy[i])&&!vis[x+dx[i]][y+dy[i]]) ans+=count(x+dx[i], y+dy[i], pos+1);
        }
    }
    else if(s[pos]=='R' && y+1<7) ans+=count(x, y+1, pos+1);
    else if(s[pos]=='U' && x-1>=0) ans+=count(x-1, y, pos+1);
    else if(s[pos]=='L' && y-1>=0) ans+=count(x, y-1, pos+1);
    else if(s[pos]=='D' && x+1<7) ans+=count(x+1, y, pos+1);
    vis[x][y]=0;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>s;
    int ans=count(0,0,0);
    cout<<ans;
    return !69;
}