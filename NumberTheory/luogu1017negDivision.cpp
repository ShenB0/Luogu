//他们对应的间隔区间内的数是相等的。那么我们只需跳到它前面一个区间的数即可，因为区间长度为-m,（m为进制）。那么就转换成：j-=m
//n-a*m=j
//n-a*m-m=j-m
//n-(a+1)*m=j-m
//也就是让商+1使得等式成立
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
inline char get_char(char x){
    return x-10+'A';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,k;
    int co;
    cin>>n>>k;
    co=n;
    string ans="";
    while(n){
        int x=n%k;
        n/=k;
        if(x<0){
            x-=k;
            n++;
        }
        if(x>=10) ans=get_char(x)+ans;
        else ans=char('0'+x)+ans;
    }
    cout<<co<<"="<<ans<<"(base"<<k<<")"<<"\n";

    return 0;
}