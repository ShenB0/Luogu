/*
我们令f(n,i,j)为n个箱子，放入i个0,j个1的方案数
则ans=∑∑f(n,i,j),
我们计算f(n,i,j),obviously,放入i个0和放入j个1是独立的，则
f(n,i,j)=g(n,i)+g(n,j)
假设g(k,n)表示向n个箱子放入k个球并且每个箱子都要有一个，我们将k个球进行分割，在k-1个间隔中插入n-1个分割就可以获得n份球了，g(k,n)=C(k-1,n-1)
回到正题，g(k,n)允许箱子个数为0，我们可以先让所有箱子都得分一个，再取走，即g(k,n)=C(n+k-1,n-1)
ans=ΣΣC(n-1,n+i-1)C(n-1,n+j-1)
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
void write(__int128 x){
    if(x<0){
        cout<<'-';
        x=-x;
    }
    if(x>9) write(x/10);
    cout<<(int)(x%10);
}
__int128 C(__int128 n,__int128 k){
    if(k>n-k) k=n-k;
    __int128 res=1;
    for(__int128 i=1;i<=k;i++){
        res=res*(n-i+1)/i;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        int nn,aa,bb;
        cin>>nn>>aa>>bb;
        __int128 n=nn,a=aa,b=bb;
        __int128 gi=C(n+a,a);
        __int128 gj=C(n+b,b);
        __int128 ans=gi*gj;
        write(ans);
        cout<<"\n";

    return 0;
}