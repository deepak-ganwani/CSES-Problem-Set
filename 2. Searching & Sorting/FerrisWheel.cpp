//Link: 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    int n, x, ans=0;
    cin>>n>>x;
    int i=0, j=n-1;
    vi v(n,0);
    rep(i,0,n) cin>>v[i];
    sort(all(v));
    while (j>=i)
    {
        if(v[i]+v[j]<=x) i++;
        j--;
        ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

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