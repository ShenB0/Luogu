//luogu3128
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  5e4 + 5;
int fa[N][20];
int diff[N], dep[N];
vector<int> adj[N];
void dfs1(int u, int par){
    diff[u] = 0;
    dep[u] = dep[par] + 1;
    fa[u][0] = par;
    for (int i = 1; (1 << i) <= dep[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1]; 
    }
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs1(v, u); 
    }
}
int dfs2(int u, int par) {
    int mx = -INF;
    for (int v : adj[u]) {
        if (v == par) continue;
        mx = max(mx, dfs2(v, u));
        diff[u] += diff[v];
    }
    mx = max(mx, diff[u]);
    return mx;
}
int LCA(int x, int y){
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            x = fa[x][i];
        }
    }
    if (x == y) return x;;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[0] = 0;
    dfs1(1, 0);
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        diff[u]++, diff[v]++;
        diff[lca]--;
        diff[fa[lca][0]]--;
    }
    int ans = dfs2(1, 0);
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
