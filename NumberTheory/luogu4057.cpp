#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
int lcm(int x,int y){
    return x/__gcd(x,y)*y;
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<lcm(a,lcm(b,c))<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}