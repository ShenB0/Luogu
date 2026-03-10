//最大生成树+倍增法LCA
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  5e5 + 10;
struct Edge{
    int u, v, w;
    bool operator < (const Edge& e) const {
        return w > e.w;
    }
};
vector<pair<int, int>> adj[N];
int dep[N], root[N], dsu[N];
bool vis[N];
int fa[N][20], val[N][20];
int find(int x) {
    if (x != dsu[x]) {
        dsu[x] = find(dsu[x]);
    }
    return dsu[x];
}
void dfs(int u, int par, int rt, int W) {
    vis[u] = true;
    root[u] = rt;
    dep[u] = dep[par] + 1;
    fa[u][0] = par;
    val[u][0] = W;
    for (int i = 1; (1 << i) <= dep[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        val[u][i] = min(val[u][i - 1], val[fa[u][i - 1]][i - 1]);
    }
    for (auto [v, w] : adj[u]) {
        if (vis[v]) continue;
        if (v == par) {
            continue;
        }
        dfs(v, u, rt, w);
    }
}
int LCA(int x, int y){
    int mi = INF;
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            mi = min(mi, val[x][i]);
            x = fa[x][i];
        } 
    } 
    if (x == y) {
        return mi;
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            mi = min(mi, val[x][i]);
            mi = min(mi, val[y][i]);
            x = fa[x][i], y = fa[y][i];
        }
    }
    mi = min(mi, val[x][0]);
    mi = min(mi, val[y][0]);
    return mi;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<Edge> edge;
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        vis[i] = false;
        dsu[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    sort(edge.begin(), edge.end());
    for (auto [u, v, w] : edge) {
        int fu = find(u);
        int fv = find(v);
        if (fu != fv) {
            dsu[fu] = fv;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    dep[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0, i, INF);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (root[x] != root[y]) {
            cout << "-1\n";
            continue;
        }
        cout << LCA(x, y) << "\n";
    }
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
