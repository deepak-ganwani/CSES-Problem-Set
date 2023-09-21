//Link: https://cses.fi/problemset/task/1071
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    int x, y;
    cin>>x>>y;
    if(x>=y)
    {
        if(x%2) cout<<(x-1)*(x-1)+y<<endl;
        else cout<<x*x+1-y<<endl;
    }
    else
    {
        if(y%2) cout<<y*y+1-x<<endl;
        else cout<<(y-1)*(y-1)+x<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    cin>>t;
    rep(tc,0,t)
    {
        // cout<<"Case #"<<tc+1<<": ";
        solve(tc);
    }
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/
/* Logic:

x>=y
	if x -> Odd	-> Increasing -> (x-1)^2+y
	if x -> Even-> Decreasing -> x^2-y+1

x<y
	if y -> Even-> Increasing -> (y-1)^2+x
	if y -> Odd	-> Decreasing -> y^2-x+1

*/