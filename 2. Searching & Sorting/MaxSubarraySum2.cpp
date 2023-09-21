#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
inline void solve(int tc){
    int n, a, b, t, ans=INT64_MIN; 
    cin>>n>>a>>b;
    vector<int> prefixSum(n+1,0);
    deque<int> pq;
    rep(i,0,n){
        cin>>t;
        prefixSum[i+1]=prefixSum[i]+t;
    }
    for(int i=a; i<=b; i++){
        while (!pq.empty() && prefixSum[i]>pq.back()) pq.pop_back();
        pq.push_back(prefixSum[i]);
    }
    for(int i=a; i<=n; i++){
        ans=max(ans, pq.front()-prefixSum[i-a]);
        if(pq.front()==prefixSum[i]) pq.pop_front();
        if(i-a+b+1<=n) {
            while (!pq.empty() && prefixSum[i-a+b+1]>pq.back()) pq.pop_back();
            pq.push_back(prefixSum[i-a+b+1]);
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}