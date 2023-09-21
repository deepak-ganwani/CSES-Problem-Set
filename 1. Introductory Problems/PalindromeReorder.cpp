//Link: https://cses.fi/problemset/task/1755
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
    map<char, int> m;
    rep(i,0,s.size()) m[s[i]]++;
    int co=0;
    for(auto k:m)
    {
        if(k.second%2) co++;
    }
    if(co>1) cout<<"NO SOLUTION"<<endl;
    else
    {
        string ans;
        if(s.size()%2)
        {
            char odd;
            int o;
            for(auto k:m)
            {
                if(k.second%2) 
                {
                    odd=k.first;
                    o=k.second;
                }
                else
                {
                    rep(i,0,k.second/2) ans+=k.first;
                }
            }
            string c=ans;
            reverse(all(c));
            rep(i,0,o) ans+=odd;
            ans+=c;
            cout<<ans<<endl;
        }
        else
        {
            for(auto k:m)
            {
                rep(i,0,k.second/2) ans+=k.first;
            }
            string c=ans;
            reverse(all(c));
            ans+=c;
            cout<<ans<<endl;
        }
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