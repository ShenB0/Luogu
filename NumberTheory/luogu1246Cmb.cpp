#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
ll pre[10];
ll C(ll n,ll m){
    ll res=1LL;
    if((n-m)<m) m=n-m;
    for(int i=1;i<=m;i++){
        res=res*(n-m+i)/i;
    }
    return res;
}
void init(){
    pre[0]=0;
    for(int i=1;i<=6;i++){
        pre[i]=pre[i-1]+C(26,i);
    }
}
void solve(){
    init();
    string s;
    cin>>s;
    int n=s.size();
    for(int i=1;i<n;i++){
        if(s[i-1]>=s[i]){
            cout<<"0\n";
            return ;
        }
    }
    char last='a'-1;
    ll ans=1LL*pre[n-1];
    for(int i=0;i<n;i++){
        for(char c=last+1;c<s[i];c++){
            ans+=C(26-(c-'a'+1),n-i-1);//C(剩余可选字母数, 剩余长度)
            //c-'a'+1就是当前字符c+1~26的个数也就是剩下比他大的字母，然后n-i-1就是剩余长度
        }
        last=s[i];
    }
    cout<<++ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}