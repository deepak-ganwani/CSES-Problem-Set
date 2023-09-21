//Link: https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    int n, m, k;
    cin>>n>>m>>k;
    vi a(n,0), b(m,0);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    sort(all(a));
    sort(all(b));
    int ans=0, i=0, j=0;
    while(i<m && j<n){
        if(b[i]>=a[j]-k && b[i]<=a[j]+k) {
            ans++;
            i++;
            j++;
        }
        else if(b[i]>a[j]) j++;
        else i++;
    }
    cout<<ans<<endl;
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