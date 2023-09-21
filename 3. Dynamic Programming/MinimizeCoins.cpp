// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define vi 			vector<int>
#define vvi 		vector<vi>
#define vpi 		vector<pair<int, int>>
#define mii 		map<int, int>
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
#define rrep(i,x,y) for(int i=x; i>=y; i--)
#define all(x) 		(x).begin(), (x).end()
#define rall(x) 	(x).rbegin(), (x).rend()
#define pb 			emplace_back
#define mp 			make_pair
#define ff 			first
#define ss 			second
#define sz(x) 		x.size()
#define SUM(x) 		accumulate(all(x), 0LL)
#define set_bits(x) __builtin_popcountll(x)
const int M=1e9+7;
const int INF=INT64_MAX;
vi dp(1e6+1, -2);
int noCoins(vi& v, int x){
    if(dp[x]!=-2) return dp[x];
    int ans=-1;
    rep(i,0,v.size()){
        if(x-v[i]<0) continue;
        int c=noCoins(v, (x-v[i]))+1;
        if(c==0) continue;
        if(ans==-1) ans=c;
        else ans=min(ans, c);
    }
    dp[x]=ans;
    return dp[x];
}
inline void solve(int tc){
    int n, x;
    cin>>n>>x;
    vi v(n);
    rep(i,0,n) {
        cin>>v[i];
        dp[v[i]]=1;
    }
    cout<<noCoins(v, x)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
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