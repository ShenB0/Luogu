//拓扑排序
//注意到u < v，本身就是拓扑序所以直接DP也可以
// for (int u = 1; u <= n; u++) {
//     for (auto v : adj[u]) {
//         dp[v] = max(dp[v], dp[u] + W[u][v]);
//     }
// }
//也可以先把无关的0度先清空跑两边拓扑也可以
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  1500 + 10;
vector<int> adj[N];
ll dp[N], W[N][N];
int cnt[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            W[i][j] = -(1LL << 60);
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v; 
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        cnt[v]++;
        W[u][v] = max(w, W[u][v]);
    }
    queue<int> q;
    fill(dp + 1, dp + 1 + n, -(1LL << 60));
    for (int i = 1;i <= n; i++) {
        if (cnt[i] == 0) {
            q.push(i);
            // dp[i] = 0;这样是错的，因为只关心1~n,这样会参杂
        }
    }
    dp[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dp[u] != -(1LL << 60)) dp[v] = max(dp[v], dp[u] + W[u][v]);//这里来避免参杂
            cnt[v]--;
            if (!cnt[v]) {
                q.push(v);
            }
        }
    }
    if (dp[n] == -(1LL << 60)) cout << "-1\n";
    else cout << dp[n] << "\n";
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