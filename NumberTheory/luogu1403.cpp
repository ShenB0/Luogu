#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6;
ll a[N+10];
ll pre[N+10];
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            a[j]++;
        }
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    cout<<pre[n]<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}