#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int goalID;
    bool haveWord = false;
    vector<string> lists;
    string lineword, single = "", numstr = "";
    while(getline(cin, lineword)){
        if(lineword == "0") break;
        for(int i = 0; i < lineword.length(); i++){
            if(isalpha(lineword[i])){
                single += lineword[i];
                if(i + 1 >= lineword.length()){
                    lists.push_back(single);
                    cout << single;
                    single = "";
                }
            }
            else if(isdigit(lineword[i])){
                numstr += lineword[i];
                if(i + 1 >= lineword.length()){
                    goalID = lists.size() - stoi(numstr); //反轉編號
                    cout << lists[goalID];
                    lists.push_back(lists[goalID]); //目標移到最前面
                    lists.erase(lists.begin() + goalID, lists.begin() + goalID + 1); //清除原本的
                    numstr = "";
                }
                else if(!isdigit(lineword[i + 1])){
                    goalID = lists.size() - stoi(numstr);
                    cout << lists[goalID];
                    lists.push_back(lists[goalID]);
                    lists.erase(lists.begin() + goalID, lists.begin() + goalID + 1);
                    numstr = "";
                }
            }
            else {
                if(single != ""){
                    lists.push_back(single);
                    cout << single;
                    single = "";
                }
                cout << lineword[i];
            }
        }
        cout << '\n';
    }
}