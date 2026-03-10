#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
const ll INF = 1LL << 60;
struct node{
    int l, r, id;
    bool operator < (const node& no) const {
        return r < no.r;
    }
}sec[N];
int n;
int a[N], last[N], tree[N], ans[N];
void update(int x, int k) {
    while (x <= n) {
        tree[x] += k;
        x += lowbit(x);
    }
}
int query(int x) {
    int res = 0;
    while (x > 0) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> sec[i].l >> sec[i].r;
        sec[i].id = i;
    }
    sort(sec, sec + m);
    memset(last, -1, sizeof(last));
    int cur = 1;
    for (int i = 0; i < m; i++) {
        auto [l, r, id] = sec[i];
        while (cur <= r) {
            if (last[a[cur]] != -1) {
                update(last[a[cur]], -1);
            }
            update(cur, 1);
            last[a[cur]] = cur;
            cur++;
        }
        ans[id] = query(r) - query(l - 1);
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
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
