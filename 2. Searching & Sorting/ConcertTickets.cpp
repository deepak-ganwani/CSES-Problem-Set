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
    int n, m;
    cin>>n>>m;
    multiset<int> v;
    int a;
    rep(i,0,n) {
        cin>>a;
        v.insert(a);
    }
    rep(i,0,m){
        cin>>a;
        auto k=v.upper_bound(a);
        if(k==v.begin()) cout<<-1<<endl;
        else{
            cout<<*(--k)<<endl;
            v.erase(k);
        }
    }
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