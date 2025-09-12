#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> out[10001];
vector<int> Cellhave;
void cells(int host);

int main(){
    int mass[10001] = {0}, n, m, a, b, MaxMass = -1, MaxCell;
    cin >> n >> m; //n細胞數, m動作
    fill(mass + 1, mass + n + 1, 10);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(mass[a] == mass[b] || mass[a] > mass[b]){
            mass[a] += mass[b];
            mass[b] = 0;
            out[a].push(b);
        }
        else if(mass[a] < mass[b]){
            mass[b] += mass[a];
            mass[a] = 0;
            out[b].push(a);
        }
    }
    for(int i = 1; i <= n; i++){
        if(MaxMass < mass[i]){
            MaxCell = i;
            MaxMass = mass[i];
        }
    }
    cout << MaxCell << '\n';
    out[MaxCell].push(MaxCell);
    cells(MaxCell);
    sort(Cellhave.begin(), Cellhave.end());
    for(auto it : Cellhave){
        cout << it << " ";
    }
}

void cells(int host){
    while(!out[host].empty()){
        int next = out[host].front();
        Cellhave.push_back(next);
        out[host].pop();
        cells(next);
    }
}