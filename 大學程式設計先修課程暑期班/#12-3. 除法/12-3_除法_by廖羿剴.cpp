#include <iostream>
#include <set>
#include <string>
using namespace std;

int numarr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool visit[10] = {false}, found = false;
set<int> check; //做重複檢查
string num = "";
void P(int d, int n);

int main(){
    int n;
    while(cin >> n){
        found = false;
        num = "";
        if(n != 0){
            P(0, n);
            if(!found){
                cout << "There are no solutions for " << n << ".\n";
            }
        }
        else{
            break;
        }
        cout << '\n';
    }
}

void P(int d, int n){
    if(d >= 5){ //P(10, 5)
        int down = stoi(num);
        string up = to_string(n * down);
        if(up.length() != 5){ //長度不為5不要
            check.clear();
            return;
        }
        for(int i = 0; i < 5; i++){
            if(visit[up[i] - '0']){ //與前面重複不要
                check.clear();
                return;
            }
            check.insert(up[i]);
        }
        if(check.size() == 5){ //裡面沒有重複才要
            cout << up << " / " << num << " = " << n << '\n'; //不用down是因為0會消失
            found = true;
        }
        check.clear(); //每次都要clear集合
        return;
    }
    for(int i = 0; i < 10; i++){
        if(!visit[i]){
            visit[i] = true;
            num += (numarr[i] + '0');
            P(d + 1, n);
            num.pop_back();
            visit[i] = false;
        }
    }
}