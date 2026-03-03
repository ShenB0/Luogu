#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    int n,k;
    cin>>n>>k;
    unordered_set<int> a,b;
    while(k--){
        int r,c;
        cin>>r>>c;
        a.insert(r);
        b.insert(c);
    }
    ll ans=1LL;
    ll r=a.size(),c=b.size();
    ans*=1LL*(r+c)*n-1LL*r*c;
    cout<<ans<<"\n";
    return 0;
}