//DAG拓扑排序，不能用暴力DFS(下面注释)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
const ll MOD = 80112002;
vector<int> adj[N];
int ent[N], out[N];
ll num[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        out[u]++; ent[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!ent[i]) {
            num[i] = 1LL;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            ent[v]--;
            num[v] = (num[v] + num[u]) % MOD;
            if (!ent[v]) {
                q.push(v);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!out[i]) {
            ans = (ans + num[i]) % MOD;
        }
    }
    cout << ans << "\n";
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
// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using i128 = __int128;
// const int INF = 0x3f3f3f3f;
// const int N =  5e5 + 10;
// const ll MOD = 80112002;
// ll ans = 0;
// int ent[N], out[N];
// vector<int> adj[N];
// void dfs(int u){
//     if (!out[u]) {
//         ans = (ans + 1) % MOD;
//         return ;
//     }
//     for (int v : adj[u]) {
//         dfs(v);
//     }
// }
// void solve(){
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         ent[v]++;
//         out[u]++;
//         adj[u].push_back(v);
//     }
//     for (int i = 1; i <= n; i++) {
//         if (!ent[i]) {
//             dfs(i);
//         }
//     }
//     cout << ans << "\n";
// }
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     int t;
//     t = 1;
//     while (t--) solve();
//     return 0;
// }
