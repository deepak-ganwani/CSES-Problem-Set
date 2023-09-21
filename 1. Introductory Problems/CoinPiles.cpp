//Link: https://cses.fi/problemset/task/1754
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    int a, b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(b<=2*a && (a+b)%3==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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