#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5;
class SegmentTree{
    public:
    vector<int> seg;
    SegmentTree(int n) {
        seg.resize(4*n+1);
    }
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low==high) {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2]; 
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (low>=l && high<=r) return seg[ind];
        if (high<l || low>r) return 0;
        int mid=(low+high)/2;
        int left=query(2*ind+1, low, mid, l, r);
        int right=query(2*ind+2, mid+1, high, l, r);
        return left+right;
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if (low==high) {
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if (i<=mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
};
vector<int> val(N+1), v(N+1);
int dfs(vector<int>* gr, vector<pair<int, int>>& rng, int nd, int p, int s) {
    rng[nd].first=s;
    val[s]=v[nd];
    for(auto&c:gr[nd]) {
        if(c==p) continue;
        s=dfs(gr, rng, c, nd, s+1);
    }
    return rng[nd].second=s;
}
inline void solve(){
    int n, q; cin>>n>>q;
    vector<int> gr[n+1];
    for(int i=1; i<n+1; i++) cin>>v[i];
    for(int i=1; i<n; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    vector<pair<int, int>> rng(n+1, {0, INT_MAX});
    SegmentTree st(n+1);
    int x=dfs(gr, rng, 1, 0, 1);
    st.build(0, 0, n+1, val);
    for(int i=0; i<q; i++) {
        int a, b, c; cin>>a>>b;
        if(a==1) {
            cin>>c;
            st.update(0, 0, n+1, rng[b].first, c);
            val[rng[b].first]=c;
        }
        else {
            cout<<st.query(0, 0, n+1, rng[b].first, rng[b].second)<<endl;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    for(int i=0; i<t; i++) solve();
    return !69;
}