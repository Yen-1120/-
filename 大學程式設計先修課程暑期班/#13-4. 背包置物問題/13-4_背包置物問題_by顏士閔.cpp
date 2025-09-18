#include<iostream>
#include<set>
#include<string>
#include <sstream>

using namespace std;

int main()
{
    int n, k = -1, day[30], count = 0;
    string s;
    set<int> bag;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    int num, m = 0;

    while (ss >> num) {
        day[m] = num;
        m += 1;
    }

    cin >> k;

    // cout << m << endl;

    for (int i = 0; i < m; i++) {
        // cout << "第 " << i+1 << " 天：" << endl;
        if (bag.size() == k && !bag.count(day[i])) {
            count += 1;
            // cout << "count:" << count << endl;

            if (i == m - 1) {
                bag.erase(bag.begin());
                bag.insert(day[i]);
                // cout << "end" << endl;
                break;
            }
            
            set<int> need_erase = bag;
            int temp = i;
            // cout << "temp:" << temp << endl << "need_erase:";
            // for (int content : need_erase) {
            //     cout << " " << content;
            // }
            // cout << endl;
            while (need_erase.size() > 1 && temp < m-1) {
                temp += 1;
                if (need_erase.count(day[temp])) {
                    need_erase.erase(day[temp]);
                }
                // cout << "temp:" << temp << endl << "need_erase:";
                // for (int content : need_erase) {
                //     cout << " " << content;
                // }
                // cout << endl;
            }
            // cout << "取" << *need_erase.begin() << ", 放" << day[i] << endl;
            bag.erase(*need_erase.begin());
            bag.insert(day[i]);
        } else if (bag.size() < k && !bag.count(day[i])) {
            // cout << "放" << day[i] << endl;
            bag.insert(day[i]);
        } else {
            // cout << "不動" << endl;
            continue;
        }
        // cout << endl;
    }

    cout << count << endl;

    return 0;
}