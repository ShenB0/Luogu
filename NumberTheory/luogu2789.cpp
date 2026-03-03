#include<bits/stdc++.h>
using namespace std;
int n;
bool vis[10000];
int solve(int s,int num){
    int ans=0;
    if(s==0){
        if(!vis[num]){
            vis[num]=true;
            return 1;
        }else{
            return 0;
        }
    }
    if(s>0){
        for(int i=s;i>=1;i--){
            ans+=solve(s-i,num+i*(s-i));
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    cout<<solve(n,0)<<"\n";
    return 0;
}