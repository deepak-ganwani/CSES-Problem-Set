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
        seg[ind]=(seg[2*ind+1]+seg[2*ind+2]); 
    }
    int query(int ind, int low, int high, int l, int r)
    {
        if (low>=l && high<=r) return seg[ind];
        if (high<l || low>r) return 0;
        int mid=(low+high)/2;
        int left=query(2*ind+1, low, mid, l, r);
        int right=query(2*ind+2, mid+1, high, l, r);
        return (left+right);
    }
    void update(int ind, int low, int high, vector<int>& arr, int i, int val)
    {
        if (low==high) {
            arr[i]=val;
            seg[ind]=arr[i];
            return;
        }
        int mid=(low+high)/2;
        if (i<=mid) update(2*ind+1, low, mid, arr, i, val);
        else update(2*ind+2, mid+1, high, arr, i, val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
};
signed main(){
    int n, q; cin>>n>>q;
    vector<int> v(n);
    SegmentTree st(n);
    for(auto&e:v) cin>>e;
    st.build(0,0,n-1,v);
    for(int i=0; i<q; i++) {
        int a,b,c; cin>>a>>b>>c;
        if(a&1) st.update(0,0,n-1,v,b-1,c);
        else cout<<st.query(0,0,n-1,b-1,c-1)<<endl;
    }
}