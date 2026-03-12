//优化两个dfs为bfs和拓扑序统计差分避免爆栈
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 3e5 + 5;
const ll INF = 1LL << 60;
struct Edge{
    int l, r, lca;
}edge[N];
int n, m;
int fa[N][20], T[N][20];
int deg[N], d[N], diff[N];
vector<int> order;
vector<pair<int, int>> adj[N];
void bfs(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto [v, t] : adj[u]) {
            if (v == fa[u][0]) continue;
            deg[v] = deg[u] + 1;
            fa[v][0] = u;
            T[v][0] = t;
            for (int i = 1; i < 20; i++) {
                fa[v][i] = fa[fa[v][i - 1]][i - 1];
                T[v][i] = T[v][i - 1] + T[fa[v][i - 1]][i - 1];
            }
            q.push(v);
        }
    }
}
pair<int, int> LCA(int x, int y) {
    int dist = 0;
    if (deg[x] < deg[y]) {
        swap(x, y);
    }
    for (int i = 19; i >= 0; i--) {
        if (deg[x] - (1 << i) >= deg[y]) {
            dist += T[x][i];
            x = fa[x][i];
        }
    }
    if (x == y) {
        return {dist, x};
    }
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            dist += T[x][i] + T[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    dist += T[x][0] + T[y][0];
    return {dist, fa[x][0]};
}
bool check(int lim, int mx){
    memset(diff, 0, sizeof(diff));
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (d[i] > lim) {
            sum++;
            auto [l, r, lca] = edge[i];
            diff[l] += 1;
            diff[r] += 1;
            diff[lca] -= 2;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        diff[fa[u][0]] += diff[u];
    }
    for (int u = 1; u <= n; u++) {
        for (auto [v, t] : adj[u]) {
            if (v == fa[u][0]) {
                if (diff[u] == sum && t >= mx - lim) {
                    return true;
                }
            }
        }
    }
    return false;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    bfs(1);
    int mx = -1;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edge[i].l = x;
        edge[i].r = y;
        auto [dist, lca] = LCA(x, y);
        edge[i].lca = lca;
        d[i] = dist;
        mx = max(dist, mx);
    }
    int l = 0, r = mx;
    int ans = 0;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (check(mid, mx)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
