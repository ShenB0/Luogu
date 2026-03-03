#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    while(a&&b){
        if(a<b) swap(a,b);
        ans+=4*b*(a/b);
        a%=b;
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}