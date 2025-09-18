#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

// struct cmp
// {
//     bool operator()(const int &A, const int &B)
//     {
//         return A > B;
//     }
// };

int main()
{
    map<int, int> agars;
    map<int, set<int>> cells;
    int N, M;
    cin >> N >> M;
   
    for (int i = 1; i <= N; i++) {
        agars.insert({i, 10});
        cells.insert({i, {i}});
    }
    // for (auto it = agars.begin(); it != agars.end(); ++it) {
    //     cout << it->first << " "; // 遍歷 key
    // }
    // cout << "::" << endl << endl;

    while (M--) {
        int a, b;
        cin >> a >> b;
        if (agars[a] >= agars[b]) {
            agars[a] += agars[b];
            cells.at(a).insert(cells.at(b).begin(), cells.at(b).end());
            agars.erase(b);
        } else {
            agars[b] += agars[a];
            cells.at(b).insert(cells.at(a).begin(), cells.at(a).end());
            agars.erase(a);
        }
        // for (auto it = agars.begin(); it != agars.end(); ++it) {
        //     cout << it->first << " "; // 遍歷 key
        // }
        // cout << "::" << endl << endl;
    }

    int maxValue = -1, maxKey = -1;
    for (auto &p : agars) {
        if (p.second > maxValue) {
            maxValue = p.second;
            maxKey = p.first;
        }
    }
    cout << maxKey << endl;
    for (int x : cells.at(maxKey)) {
        cout << x << " ";
    }

    return 0;
}