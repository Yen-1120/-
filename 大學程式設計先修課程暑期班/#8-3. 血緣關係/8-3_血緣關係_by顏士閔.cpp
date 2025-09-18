#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int N;
int maxDistance = 0;

int dfs(int u, int p) {
    int max1 = 0, max2 = 0; // u 兩個最大的子樹深度

    for (int v : adj[u]) {
        if (v == p) continue;
        int d = 1 + dfs(v, u);
        if (d > max1) {
            max2 = max1;
            max1 = d;
        } else if (d > max2) {
            max2 = d;
        }
    }

    // 經過 u 的最長路徑 = max1 + max2
    maxDistance = max(maxDistance, max1 + max2);

    return max1; // 回傳從 u 往下的最長路徑
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    cout << maxDistance << "\n";
    return 0;
}
