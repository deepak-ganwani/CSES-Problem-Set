// WHY DO WE FALL? 
#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define vi 			vector<int>
#define pii 		pair<int, int>
#define mii 		map<int, int>
#define vvi 		vector<vi>
#define vpi 		vector<pii>
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
inline void solve(int tc){
    int n; cin>>n;
    int a, b, f=1;
    vi ans(n);
    priority_queue<pii> v;
    vector<pair<pii, int>> rd;
    rep(i,0,n){
        cin>>a>>b;
        rd.pb(mp(mp(a, b), i));
    }
    sort(all(rd));
    rep(i,0,n){
        a=rd[i].ff.ff;
        b=rd[i].ff.ss;
        if(v.empty()){
            v.push(mp(-1*b, 1));
            ans[rd[i].ss]=1;
        }
        else{
            pii tp=v.top();
            if(-1*tp.ff<a){
                v.pop();
                v.push(mp(-1*b,tp.ss));
                ans[rd[i].ss]=tp.ss;
            }
            else{
                ans[rd[i].ss]=sz(v)+1;
                v.push(mp(-1*b,sz(v)+1));
            }
        }
    }
    cout<<sz(v)<<endl;
    rep(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;
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