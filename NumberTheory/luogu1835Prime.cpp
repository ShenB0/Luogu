//线性筛思想用小于等于√R的小素数筛选[L,R]范围的合数再统计质数和
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=5e4+5;
void solve(){
    vector<int> prime;
    vector<bool> is_prime(N,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=N;i++){
        if(is_prime[i]) prime.push_back(i);
        for(auto& e:prime){
            if(e*i>N) break;
            is_prime[e*i]=false;
            if(i%e==0) break;
        }
    }
    ll l,r;
    cin>>l>>r;
    vector<bool> isPrime(r-l+1,true);
    if(l==1) isPrime[0]=false;
    for(auto& e:prime){
        ll beg=max(1LL*e*e,1LL*(l+e-1)/e*e);
        if(beg>r) continue;
        for(ll i=beg;i<=r;i+=e){
            isPrime[i-l]=false;
        }
    }
    ll ans=0;
    for(int i=0;i<=r-l;i++){
        if(isPrime[i]) ans++;
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
//the Meissel, Lehmer, Lagarias, Miller, Odlyzko method