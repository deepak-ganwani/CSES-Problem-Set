#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M=1e9+7; //998244353;
const int M2=1e9+6;
int binpow(int a, int b, int m=M){
    if(b==0) return 1;
    int ans=binpow(a,b/2,m);
    int res=ans*ans%m;
    if(b%2) return res*a%m;
    return res;
}
int geo_sum(int a, int n) {
    int ans=(binpow(a, n+1)-1+M)%M;
    ans=(ans*(binpow(a-1, M-2)))%M;
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(9);
    int n; cin>>n;
    vector<int> p(n), e(n);
    for(int i=0; i<n; i++) cin>>p[i]>>e[i];
    int num=1, sum=1, prod=1;
    int num2=1, f=0;
    for(int i=0; i<n; i++) {
        num=(num*(e[i]+1))%M;
        if(!f && e[i]%2) {
            num2=(num2*((e[i]+1)/2))%M2;
            f++;
        }
        else num2=(num2*(e[i]+1))%M2;
        sum=(sum*geo_sum(p[i], e[i]))%M;
    }
    for(int i=0; i<n; i++) {
        if(!f) prod=(prod*binpow(p[i], ((e[i]/2)*num2)%M2))%M;
        else prod=(prod*binpow(p[i], (e[i]*num2)%M2))%M;
    }
    cout<<num<<' '<<sum<<' '<<prod;
    return !69;
}