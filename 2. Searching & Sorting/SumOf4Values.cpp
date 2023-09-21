#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, t; cin>>n>>t;
    vector<pair<int, int>> v(n);
    vector<int> ans;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        v[i]=make_pair(x, i+1);
    }
    sort(v.begin(), v.end());
    for(int a=0; a<n-3; a++){
        if(a && v[a].first==v[a-1].first) continue;
        for(int b=a+1; b<n-2; b++){
            if(b!=a+1 && v[b].first==v[b-1].first) continue;
            int c=b+1, d=n-1;
            while(c<d){
                int s=v[a].first+v[b].first+v[c].first+v[d].first;
                if(s==t){
                    ans.push_back(v[a].second);
                    ans.push_back(v[b].second);
                    ans.push_back(v[c].second);
                    ans.push_back(v[d].second);
                    sort(ans.begin(), ans.end());
                    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
                    return 0;
                }
                else if(s>t) d--;
                else c++;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}