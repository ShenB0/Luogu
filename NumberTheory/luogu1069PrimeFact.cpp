//Si^t​≡0(modM)
//整数 x 要 “能整除 M”，必须至少包含 M 的所有质因子的所有次方数。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
map<ll,ll> factor(ll x){//返回x的所有质因数
    map<ll,ll> r;
    for(ll i=2;i*i<=x;i++)
        while(x%i==0) r[i]++, x/=i;
    if(x>1) r[x]++;
    return r;
}
void solve(){
    ll N,m1,m2;
    cin>>N>>m1>>m2;
    vector<ll> S(N);
    for(ll &x:S) cin>>x;
    auto fm=factor(m1);//分解m1质因数
    for(auto &kv:fm) kv.second*=m2;//把指数乘进数量里
    ll ans=LLONG_MAX;
    for(ll si:S){//遍历所有抽取的数
        auto fs=factor(si);//分解si质因数
        ll t=0;
        bool ok=true;
        for(auto &kv:fm){//遍历m1质因数和数量
            ll p=kv.first;//质因数
            ll need=kv.second;//指数
            if(fs[p]==0){ok=false;break;}//如果si没有m1的某个质因数，返回退出
            ll e=fs[p];//取出si当前因数的指数
            t=max(t,(need+e-1)/e);//t⋅e≥need，t≥need/e,t=⌈need/e⌉=(need+e-1)/e
        }
        if(ok) ans=min(ans,t);//取最小时间
    }
    cout<<(ans==LLONG_MAX?-1:ans)<<"\n";//输出
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}