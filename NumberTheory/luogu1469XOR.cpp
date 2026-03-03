// k 个相同的数的异或和，当 k 为奇数时，结果是这个数本身，否则结果是 0。
// 任何数与 0 的异或值是它本身。
// 异或满足交换律和结合律
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
int read(){
    int res=0,neg=1;;
    char x=getchar();
    while(x<'0'||x>'9'){
        if(x=='-') neg=-1;
        x=getchar();
    }
    while('0'<=x&&x<='9'){
        res=res*10+x-'0';
        x=getchar();
    }
    return neg*res;
}
int n,ans=0;
int main(){
    // ios::sync_with_stdio(false);   影响getchar();
    // cin.tie(nullptr);cout.tie(nullptr); 
    n=read();
    for(int i=0;i<n;i++){
        ans^=read();
    }
    printf("%d\n",ans);
    return 0;
}