#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int MAX=1e6;
int a[N];
void solve(){
    int n;
    cin>>n;
    map<int,int> mp,cnt;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        cnt[a[i]]=0;
    }
    for(auto& [v,c]:mp){
        for(int i=(2*v);i<=MAX;i+=v){
            if(mp.count(i)) cnt[i]+=c;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<cnt[a[i]]+mp[a[i]]-1<<"\n";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}