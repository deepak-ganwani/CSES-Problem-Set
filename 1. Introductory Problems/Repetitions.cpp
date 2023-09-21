//Link: https://cses.fi/problemset/task/1069
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define rep(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pb emplace_back

void solve(int tc){
    string s;
    cin>>s;
    int m=1, c=1;
    rep(i,1,s.size())
    {
        if(s[i]==s[i-1]) c++;
        else
        {
            m=max(m,c);
            c=1;
        }
    }
    if(c>m) m=c;
    cout<<m<<endl;
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