//DAG最长路，拓扑序DP
//由于前置任务会在1~k - 1中，所以也可以直接用DP递推不需要拓扑
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const int N =  1e4 + 5;
int pre[N], num[N], dp[N];
int T[N];
vector<int> adj[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v, t, u;
        cin >> v >> T[i] >> u;
        while (u) {
            adj[u].push_back(v);
            num[v]++;
            cin >> u;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            q.push(i);
            dp[i] = 0;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : adj[u]) {
            pre[v]++;
            if (pre[v] == num[v]) {
                q.push(v);
            }
            dp[v] = max(dp[v], dp[u] + T[u]);
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dp[i] + T[i]);
    }
    cout << mx << "\n";
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