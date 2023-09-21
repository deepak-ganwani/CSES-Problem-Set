//Link: https://cses.fi/problemset/task/1617
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    int n;
    cin>>n;
    int a=2, M=1e9+7;
    rep(i,0,n-1)
    {
        a=(a*2)%M;
    }
    cout<<a<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
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