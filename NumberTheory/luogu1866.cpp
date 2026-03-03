#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
const int Mod=1e9+7;
int a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll ans=1;
    for(int i=0;i<n;i++){
        ans=ans*(a[i]-i)%Mod;
    }
    cout<<ans<<"\n";
    return 0;
}