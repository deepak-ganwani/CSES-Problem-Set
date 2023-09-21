#include <bits/stdc++.h>
using namespace std;
int power(int a, int b){
    if(b==0) return 1;
    int ans=power(a,b/2);
    if(b%2) return ans*ans*a;
    return ans*ans;
}
inline void solve(int tc){
    int n; cin>>n;
    bitset<17> a;
    for (int i = 0; i < power(2,n); i++)
    {
        a=(i^(i>>1));
        for(int j=0; j<n; j++) cout<<a[j];
        cout<<endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve(1);
    return !69;
}