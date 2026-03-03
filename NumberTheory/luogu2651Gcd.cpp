#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
int a[N];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int mu=a[1]/__gcd(a[0],a[1]);
    for(int i=2;i<n;i++){
        mu/=__gcd(mu,a[i]);
    }
    if(mu==1) cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}