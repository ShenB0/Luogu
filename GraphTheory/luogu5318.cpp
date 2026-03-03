#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  2e5 + 10;
bool vis[N];
vector<int> adj[N];
void dfs(int now){
    cout << now << " ";
    for (auto& p : adj[now]) {
        if (vis[p]) continue;
        vis[p] = true;
        dfs(p);
    }
}
void bfs(){
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto& p : adj[x]) {
            if (vis[p]) continue;
            vis[p] = true;
            q.push(p);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    dfs(1);
    cout << "\n";
    memset(vis, false, sizeof(vis));
    vis[1] = true;
    bfs();
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