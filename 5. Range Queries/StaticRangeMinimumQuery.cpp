#include<bits/stdc++.h>
using namespace std;
#define int long long
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
        seg[ind]=min(seg[2*ind+1], seg[2*ind+2]); 
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (low>=l && high<=r) return seg[ind];
        if (high<l || low>r) return INT64_MAX;
        int mid=(low+high)/2;
        int left=query(2*ind+1, low, mid, l, r);
        int right=query(2*ind+2, mid+1, high, l, r);
        return min(left, right);
    }
};
signed main(){
    int n, q; cin>>n>>q;
    SegmentTree st(n);
    vector<int> v(n);
    for(auto&e:v) cin>>e;
    st.build(0, 0, n-1, v);
    for(int i=0; i<q; i++) {
        int l, r; cin>>l>>r;
        cout<<st.query(0, 0, n-1, l-1, r-1)<<endl;
    }
    return 0;
}