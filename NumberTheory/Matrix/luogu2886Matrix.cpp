#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  200;
int Hash[1005];
struct Matrix{
    int a[N][N];
};
Matrix mul(Matrix x, Matrix y){
    Matrix res;
    memset(res.a, INF, sizeof(res.a));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res.a[i][j] = min(res.a[i][j], x.a[i][k] + y.a[k][j]);
            }
        }
    }
    return res;
}
Matrix qpow(Matrix m, int b){
    Matrix res;
    memset(res.a, INF, sizeof(res.a));
    for(int i=0;i<N;i++) res.a[i][i]=0;
    while (b) {
        if (b & 1) {
            res = mul(res, m);
        }
        b >>= 1;
        m = mul(m, m);
    }
    return res;
}
void solve(){
    int n, t, s, e;
    cin >> n >> t >> s >> e;
    Matrix graph;
    int cur = 0;
    memset(graph.a, INF, sizeof(graph.a));
    memset(Hash, -1, sizeof(Hash));
    for (int i = 0; i < t; i++) {
        int u, v, w;
        cin >> w >> u >> v;
        if (Hash[u] == -1) Hash[u] = cur++;
        if (Hash[v] == -1) Hash[v] = cur++;
        graph.a[Hash[v]][Hash[u]] = min(graph.a[Hash[v]][Hash[u]], w);
        graph.a[Hash[u]][Hash[v]] = min(graph.a[Hash[u]][Hash[v]], w);
    }
    graph = qpow(graph, n);
    cout << graph.a[Hash[s]][Hash[e]] << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}