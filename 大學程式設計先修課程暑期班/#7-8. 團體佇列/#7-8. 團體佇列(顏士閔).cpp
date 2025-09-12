#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

int main()
{
    int t, count = 0;
    while (cin >> t && t != 0) {
        count += 1;
        map<int, int> PtoGroup;    // 人 -> 團體
        for (int i = 0; i < t; i++) {
            int n;
            cin >> n;
            while (n--) {
                int x;
                cin >> x;
                PtoGroup.insert({x, i});
            }
        }
        map<int, queue<int>> groups;
        queue<int> groupOrder;
        string command;
        int x;
        cout << "Scenario #" << count << endl;
        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                cin >> x;
                if (groups.count(PtoGroup.at(x))) {
                    groups.at(PtoGroup.at(x)).push(x);
                } else {
                    groupOrder.push(PtoGroup.at(x));
                    groups.insert({PtoGroup.at(x), {}});
                    groups.at(PtoGroup.at(x)).push(x);
                }
            } else if (command == "DEQUEUE") {
                cout << groups.at(groupOrder.front()).front() << endl;
                groups.at(groupOrder.front()).pop();
                if (groups.at(groupOrder.front()).empty()) {
                    groups.erase(groupOrder.front());
                    groupOrder.pop();
                }
            }
        }
    }
}