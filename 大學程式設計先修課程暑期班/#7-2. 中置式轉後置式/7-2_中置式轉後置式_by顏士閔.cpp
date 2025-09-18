#include<iostream>
#include<vector>

using namespace std;

int main()
{
    string t;
    vector<string> text, record;

    while(true) {
        getline(cin, t);
        if (t == "0") {
            break;
        }
        text.push_back(t);
    }

    for (string nows : text) {
        for (int i = 0; i < nows.size(); i++) {
            if (isdigit(nows[i])) {
                int n = 0;
                while (isdigit(nows[i])) {
                    n = n*10 + (nows[i]-'0');
                    i++;
                    if (i >= nows.size()) {
                        break;
                    }
                }
                i--;
                // cout << n;
                string ts = record[record.size() - n];
                cout << ts;
                for (int j = 0; j < record.size(); j++) {
                    if (record[j] == ts) {
                        record.erase(record.begin() + j);
                    }
                }
                record.push_back(ts);
            } else if (isalpha(nows[i])) {
                string s = "";
                while (isalpha(nows[i])) {
                    s += nows[i];
                    i++;
                    if (i >= nows.size()) {
                        break;
                    }
                }
                i--;
                cout << s;
                record.push_back(s);
            } else {
                cout << nows[i];
            }
        }
        cout << endl;
    }
}