//Euler φ 函数的核心公式:φ(x)=x∏​(1−1/p​),p|x
//在 1~x 中，有 1/p 的数被质数 p 整除，所以删除这些就剩下互质的
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int MAXN=1e6+10;
vector<int> prime;
vector<bool> is_prime(N,true);
void euler(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=MAXN;i++){
        if(is_prime[i]) prime.push_back(i);
        for(auto& e:prime){
            if(e*i>MAXN) break;
            is_prime[e*i]=false;
            if(i%e==0) break;
        }
    }
}
void solve(){
    euler();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t;
    t=1;
    while(t--) solve();
    return 0;
}