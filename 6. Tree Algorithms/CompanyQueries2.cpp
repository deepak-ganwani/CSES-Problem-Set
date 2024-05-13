#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+2; //998244353;
int suc[N][20];
int dep[N];
vector<int> gr[N];
void calc_depth(int n, int p, int d) {
    dep[n]=d;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        calc_depth(c, n, d+1);
    }
}
/*
THIS IS O((logN)^2) approach
- It won't get accepted on CSES, due to extreme tight constraints
- But will work on all other platforms
*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q; cin>>n>>q;
    for(int i=2; i<n+1; i++) {
        int a; cin>>a;
        suc[i][0]=a;
        gr[i].push_back(a);
        gr[a].push_back(i);
    }
    calc_depth(1, 0, 0);
    for(int j=1; j<20; j++) {
        for(int i=1; i<n+1; i++) suc[i][j]=suc[suc[i][j-1]][j-1];
    }
    function<int(int, int)> bin_lift=[&](int n, int j)->int{
        for(int i=0; i<20; i++) {
            if(j&(1<<i)) n=suc[n][i];
        }
        return n;
    };
    for(int i=0; i<q; i++) {
        int a, b; cin>>a>>b;
        if(dep[a]>dep[b]) swap(a,b);
        b=bin_lift(b, dep[b]-dep[a]);
        if(a==b) {
            cout<<a<<endl;
            continue;
        }
        int lo=1, hi=dep[a]+1, ans=0;
        while(lo<=hi) {
            int mid=lo+(hi-lo)/2;
            int new_a=bin_lift(a, mid);
            int new_b=bin_lift(b, mid);
            if(new_a==new_b) {
                ans=new_a;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        cout<<ans<<endl;
    }
    return !69;
}