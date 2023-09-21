#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define vi 			vector<int>
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
inline void solve(int tc){
    int n, t, c=0, curr=0; cin>>n>>t;
    vi v(n);
    rep(i,0,n) cin>>v[i];
    rep(i,0,n){
        if(t==0) c++;
        if(t>=v[i]){
            curr++;
            t-=v[i];
        }
        else{
            t+=v[i-curr];
            i--;
            curr--;
        }
    }
    if(t==0) c++;
    cout<<c<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}