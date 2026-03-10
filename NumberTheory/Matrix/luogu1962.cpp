//斐波那契数列
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
struct Matrix{
    ll m[2][2];
};
Matrix mul(Matrix p, Matrix q) {
    Matrix res;
    memset(res.m, 0, sizeof(res.m));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res.m[i][j] = (res.m[i][j] + p.m[i][k] * q.m[k][j]) % MOD;
            }
        }
    }   
    return res;
}
Matrix qpow(Matrix x, ll c){
    Matrix res;
    res.m[0][0] = res.m[1][1] = 1;
    res.m[0][1] = res.m[1][0] = 0;
    while (c) {
        if (c & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        c >>= 1;
    }
    return res;
}
int main(){
    Matrix q;
    q.m[0][0] = q.m[0][1] =q.m[1][0] = 1;
    q.m[1][1] = 0;
    // 2  1  1   1
    //  =      *  
    // 1  1  0   1
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    Matrix ans = qpow(q, n - 1);
    ll Fn = ans.m[0][0];
    cout << Fn % MOD<< "\n";
    
}
