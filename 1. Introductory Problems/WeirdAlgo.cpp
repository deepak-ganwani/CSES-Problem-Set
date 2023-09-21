//Link: https://cses.fi/problemset/task/1068/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int n){
    if(n==1) return;
    if(n==2) 
    {
        cout<<1<<endl; 
        return;
    }
    else if(n%2) 
    {
        n=n*3+1;
        cout<<n<<" ";
        solve(n);
    }
    else
    {
        n=n/2;
        cout<<n<<" ";
        solve(n);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    // cin>>t;
    rep(tc,0,t)
    {
        // cout<<"Case #"<<tc+1<<": ";
        int n;
        cin>>n;
        cout<<n<<" ";
        solve(n);
        // solve(tc);
    }
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/