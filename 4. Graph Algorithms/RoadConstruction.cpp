#include<bits/stdc++.h>
using namespace std;
#define int long long

class DisjointSet{
public:
    vector<int> parent, size;
    int max=1, islands=0;
    DisjointSet(int n) {
        islands=n;
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findParent(int node) { 
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }

    void fus(int u, int v) {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            if(size[ulp_v]>max) max=size[ulp_v];
            islands--;
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            if(size[ulp_u]>max) max=size[ulp_u];
            islands--;
        }
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    DisjointSet ds(n);
    for(int i=0; i<m; i++) {
        int u, v; cin>>u>>v;
        ds.fus(u, v);
        cout<<ds.islands<<" "<<ds.max<<endl;
    }
    return 0;
}