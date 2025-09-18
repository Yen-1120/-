#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct coordinate
{
    int x, y;
};

const coordinate Ways[8] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int total;

bool lexSmaller(const vector<vector<int>> &a, const vector<vector<int>> &b) {   // a, b 大小一定依樣
    int rows = a.size();
    int cols = a[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] != b[i][j]) return a[i][j] < b[i][j];
        }
    }
    return false;
}

void DFS(int step, coordinate co, vector<vector<int>> &a, vector<vector<bool>> &visited, vector<vector<int>> &best)
{
    if (step == total) {
        if (best.empty() || lexSmaller(a, best)) {
            best = a;
        }
    }  else {
        for (auto w : Ways) {
            int nx = co.x + w.x;
            int ny = co.y + w.y;
            if (nx >= 0 && nx < a.size() && ny >= 0 && ny < a[0].size() && !visited[nx][ny]) {
                DFS(step + 1, {nx, ny}, a, visited, best);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    total = 3 * n - 1;
    vector<vector<int>> a(3, vector<int>(n, 0));
    vector<vector<bool>> visited(3, vector<bool>(n, false));
    vector<vector<int>> best(3, vector<int>(n, 0));

    DFS(0, {0, 0}, a, visited, best);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (!(i == 2 && j == n-1)) { cout << " "; }
        }
    }
}