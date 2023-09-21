#include <bits/stdc++.h>
using namespace std;
#define int 		long long
#define endl 		'\n'
#define rep(i,x,y) 	for(int i=x; i<y; i++)
string s[8];
int cc;
map<int, int> row, col, dia1, dia2;
bool check(int x, int y){
    if(row[x]) return false;
    if(col[y]) return false;
    if(dia1[x-y]) return false;
    if(dia2[x+y]) return false;
    return true;
}
void queenPlace(int x){
    rep(i,0,8){
        if(s[x][i]!='*' && check(x, i)){
            row[x]++;
            col[i]++;
            dia1[x-i]++;
            dia2[x+i]++;
            if(x==7) cc++;
            else queenPlace(x+1);
            row[x]--;
            col[i]--;
            dia1[x-i]--;
            dia2[x+i]--;
        }
    }
}
inline void solve(int tc){
    rep(i,0,8) cin>>s[i];
    queenPlace(0);
    cout<<cc<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t=1;
    // cin>>t;
    rep(tc,0,t)
    {
        // cout<<"Case #"<<tc+1<<": ";
        solve(tc);
    }
    return !69;
}
/*
    It’s only after we’ve lost everything that we’re free to do anything.
    ~ Tyler Durden
*/