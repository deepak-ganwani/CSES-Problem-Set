//Link: https://cses.fi/problemset/task/1070
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
    int a=n;
    int b=n/2;
    if(n==1) cout<<1<<endl;
    else if(n<4) cout<<"NO SOLUTION"<<endl;
    else if(n==4) cout<<"2 4 1 3"<<endl;
    else
    {
        rep(i,0,n/2)
        {
            cout<<a<<" "<<b<<" ";
            a--;
            b--;
        }
        if(n%2)cout<<ceil(1.0*n/2)<<endl;
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
        solve(tc);
    }
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/