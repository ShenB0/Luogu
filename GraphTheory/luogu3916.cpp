//反向建图+逆序DFS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  1e5 + 10;
vector<int> adj[N];
int ans[N];
void dfs(int u, int mx){
    if (ans[u]) {
        return ;
    }
    ans[u] = mx;
    for (auto& v : adj[u]) {
        dfs(v, mx);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    for (int i = n; i >= 1; i--) {
        if (!ans[i]) dfs(i, i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
