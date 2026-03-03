//两个数的积等于它们最大公约数和它们最小公倍数的积。
//x×y=P×Q
//gcd(x,y)=P
//lcm(x,y)=Q
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;

void solve(){
    int x,y;
    cin>>x>>y;
    int multi=1LL*x*y;
    int ans=0;
    for(int i=1;i*i<=multi;i++){
        if(multi%i==0&&__gcd(i,multi/i)==x) ans+=(i!=multi/i)?2:1;
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