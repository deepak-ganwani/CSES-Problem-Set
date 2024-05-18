#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+2;
vector<int> gr[N];
int suc[N][20];
int dep[N];
int ans[N];
void subtree_sum(int n, int p) {
    int x=0;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        subtree_sum(c, n);
        x+=ans[c];
    }
    ans[n]+=x;
}
void calc_depth(int n, int p, int d) {
    dep[n]=d;
    for(auto&c:gr[n]) {
        if(c==p) continue;
        calc_depth(c, n, d+1);
    }
}
void fill_succ(int n, int p) {
    suc[n][0]=p;
    for(int i=1; i<20; i++) {
        if(suc[n][i-1]) suc[n][i]=suc[suc[n][i-1]][i-1];
    }
    for(auto&c:gr[n]) {
        if(c==p) continue;
        fill_succ(c, n);
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
    cout<<fixed<<setprecision(9);
    int n, q; cin>>n>>q;
    for(int i=1; i<n; i++) {
        int a, b; cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    calc_depth(1, 0, 0);
    fill_succ(1, 0);
    while(q--) {
        int a, b; cin>>a>>b;
        ans[a]++;
        ans[b]++;
        int lca=LCA(a, b);
        ans[lca]--;
        ans[bin_lift(lca, 1)]--;
    }
    subtree_sum(1, 0);
    for(int i=1; i<n+1; i++) cout<<ans[i]<<' ';
    cout<<endl;
    return !69;
}