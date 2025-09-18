#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
    int n, Team_num, No, En_No, a = 1;
    map<int, int> group;
    string commands;
    queue<int> team_qu[1000];
    queue<int> start;
    while(cin >> n){
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            while(!team_qu[i].empty()) team_qu[i].pop();
        }
        while(!start.empty()) start.pop();
        group.clear();

        for(int i = 0; i < n; i++){
            cin >> Team_num;
            for(int t = 0; t < Team_num; t++){  
                cin >> No;  
                group[No] = i;
            }
        }
        cout << "Scenario #" << a++ << '\n';
        do{
            cin >> commands;
            if(commands == "ENQUEUE"){
                cin >> En_No;
                if(team_qu[group[En_No]].empty()){
                    team_qu[group[En_No]].push(En_No);
                    start.push(group[En_No]);
                }
                else{
                    team_qu[group[En_No]].push(En_No);
                }
            }
            else if(commands == "DEQUEUE"){
                int s = start.front();
                cout << team_qu[s].front() << '\n';
                team_qu[s].pop();
                if(team_qu[s].empty()){
                    start.pop();
                }
            }
        }while(commands != "STOP");
        cout << '\n';
    }
}