#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
vector<int> gr[N];
int suc[N][20];
int dep[N];
void calc_depth(int n, int p, int d) {
    dep[n]=d;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        calc_depth(c, n, d+1);
    }
}
int bin_lift(int n, int j) {
    for(int i=0; i<20; i++) {
        if(j&(1<<i)) n=suc[n][i];
    }
    return n;
}
int LCA(int u, int v) {
    if(dep[u]>dep[v]) swap(u, v);
    v=bin_lift(v, dep[v]-dep[u]);
    if(u==v) return u;
    for(int i=19; i>=0; i--) {
        if(suc[u][i]==suc[v][i]) continue;
        u=suc[u][i];
        v=suc[v][i];
    }
    return bin_lift(u, 1);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, q; cin>>n>>q;
    for(int i=2; i<n+1; i++) {
        int a; cin>>a;
        suc[i][0]=a;
        gr[a].push_back(i);
        gr[i].push_back(a);
    }
    for(int j=1; j<20; j++) {
        for(int i=1; i<n+1; i++) suc[i][j]=suc[suc[i][j-1]][j-1];
    }
    calc_depth(1, 0, 0);
    for(int i=0; i<q; i++) {
        int a, b; cin>>a>>b;
        cout<<LCA(a, b)<<endl;
    }
    return !69;
}