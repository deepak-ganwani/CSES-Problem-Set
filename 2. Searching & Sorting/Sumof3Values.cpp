// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define vi 			vector<int>
#define vpi 		vector<pair<int, int>>
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
#define all(x) 		(x).begin(), (x).end()
#define pb 			emplace_back
#define mp 			make_pair
#define ff 			first
#define ss 			second
inline void solve(int tc){
    int n, t, a; cin>>n>>t;
    vpi v;
    rep(i,0,n){
        cin>>a;
        v.push_back(mp(a, i+1));
    }
    sort(all(v));
    a=0;
    rep(i,0,n-2){
        int s=t-v[i].ff;
        int x=i+1, y=n-1;
        while(x<y){
            if(v[x].ff+v[y].ff==s){
                a=1;
                vi t;
                t.pb(v[i].ss);
                t.pb(v[x].ss);
                t.pb(v[y].ss);
                sort(all(t));
                cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
                x++;
                y--;
                break;
            }
            else if(v[x].ff+v[y].ff>s) y--;
            else x++;
        }
    }
    if(a==0) cout<<"IMPOSSIBLE"<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/