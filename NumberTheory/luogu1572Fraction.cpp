//对于所有测试点，输入计算式长度在 100 以内，分子、分母在 1000 以内。同时保证，直接从前往后直接计算分数的和或者差，然后立刻化简，这么做的中间结果不会超过 int 的范围。
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<ll> num;
    vector<char> sym;
    ll x=0;
    int pos=0;
    bool neg=false;
    if(s[0]=='-'){
        neg=true;
        pos=1;
    }
    for(int i=pos;i<n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            x=10*x+s[i]-'0';
        }else if(s[i]=='/'){
            num.push_back(x);
            x=0;
        }else{
            sym.push_back(s[i]);
            num.push_back(x);
            x=0;
        }
    }
    num.push_back(x);
    if(neg) num[0]=-num[0];
    int m=num.size();
    int j=0;
    ll son=num[0],par=num[1];
    for(int i=2;i<m;i+=2){
        ll a=num[i];
        if(sym[j++]=='-') a=-a;
        ll b=num[i+1];
        ll g1=__gcd(par, b);
        ll par1=par/g1;
        ll b1=b/g1;
        ll new_son=son*b1+a*par1;
        ll new_par=par1*b;
        ll g2=__gcd(llabs(new_son),new_par);
        son=new_son/g2;
        par=new_par/g2;
    }
    ll g=__gcd(llabs(son), par);
    son/=g;
    par/=g;
    cout<<son;
    if(par!=1) cout<<"/"<<par;
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}