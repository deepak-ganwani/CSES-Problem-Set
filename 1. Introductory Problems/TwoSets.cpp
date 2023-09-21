//Link: https://cses.fi/problemset/task/1092
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
    int x=n;
    vi a(n,0), b, c;
    rep(i,0,n) 
    {
        a[i]=x;
        x--;
    }
    int r=n*(n+1)/2;
    if(r%2) cout<<"NO"<<endl;
    else
    {
        r/=2;
        cout<<"YES"<<endl;
        int s=0, t=1;
        rep(i,0,n)
        {
            s+=a[i];
            if(t && s<=r) b.pb(a[i]);
            else 
            {
                s-=a[i];
                c.pb(a[i]);
            }
            if(t && s==r) t=0;
        }
        sort(all(b));
        sort(all(c));
        cout<<b.size()<<endl;
        rep(i,0,b.size()) cout<<b[i]<<" ";
        cout<<endl;
        cout<<c.size()<<endl;
        rep(i,0,c.size()) cout<<c[i]<<" ";
        cout<<endl;
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