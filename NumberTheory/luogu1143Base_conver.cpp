#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
inline int get_num(char x){
    return x-'A'+10;
}
inline char get_char(int x){
    return x-10+'A';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    string s;
    int n_;
    cin>>n>>s>>n_;
    int len=s.size();
    int num=0;
    for(int i=0;i<len;i++){
        if(isdigit(s[i])){
            num=num*n+s[i]-'0';
        }else{
            num=num*n+get_num(s[i]);
        }
    }
    string ans="";
    while(num){
        int val=num%n_;
        if(val>=10){
            ans=string(1, get_char(val))+ans;
        }else{
            ans=char('0'+val)+ans;
        }
        num/=n_;
    }
    cout<<ans<<"\n";
    return 0;
}